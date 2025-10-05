### Install Dependencies

- eval "$(/opt/homebrew/bin/brew shellenv)" # switch to arm64 homebrew
- brew install libssh

### Run Cowrie

- docker run -p 2222:2222 cowrie/cowrie:latest
- ssh -p 2222 root@localhost # verify ssh connection, password -> cowrie

### Begin Bruteforce

- make
- ./hydra_ssh

<pre>
MacBook-Air-2:hydra-bruteforce anish$ ./hydra_ssh 
[-] Failed: adverbial:polina
[-] Failed: adventurous:01011980
[-] Failed: adversaria:freepass
[-] Failed: adverb:wildcat
[-] Failed: adventurism:cowrie
[-] Failed: adventuresome:brazil
[-] Failed: adventitious:crazy
[-] Failed: adventuress:1978
[-] Failed: adventure:hard
[-] Failed: adventurer:england
[+] SUCCESS: root@localhost -> 123456789q
[-] Failed: adventitia:zxc123
[-] Failed: advection:wombat
[-] Failed: adventist:alpha
[-] Failed: advent:avatar
MacBook-Air-2:hydra-bruteforce anish$ 
</pre>

### Cowrie Logs

<pre>
MacBook-Air-2:hydra-bruteforce anish$ docker run -p 2222:2222 cowrie/cowrie:latest

/cowrie/cowrie-env/lib/python3.11/site-packages/twisted/conch/ssh/transport.py:105: CryptographyDeprecationWarning: TripleDES has been moved to cryptography.hazmat.decrepit.ciphers.algorithms.TripleDES and will be removed from cryptography.hazmat.primitives.ciphers.algorithms in 48.0.0.
  b"3des-cbc": (algorithms.TripleDES, 24, modes.CBC),
/cowrie/cowrie-env/lib/python3.11/site-packages/twisted/conch/ssh/transport.py:112: CryptographyDeprecationWarning: TripleDES has been moved to cryptography.hazmat.decrepit.ciphers.algorithms.TripleDES and will be removed from cryptography.hazmat.primitives.ciphers.algorithms in 48.0.0.
  b"3des-ctr": (algorithms.TripleDES, 24, modes.CTR),
2025-02-14T09:58:05+0000 [-] Reading configuration from ['/cowrie/cowrie-git/etc/cowrie.cfg.dist']
2025-02-14T09:58:05+0000 [-] Python Version 3.11.2 (main, Sep 14 2024, 03:00:30) [GCC 12.2.0]
2025-02-14T09:58:05+0000 [-] Twisted Version 24.10.0
2025-02-14T09:58:05+0000 [-] Cowrie Version 2.6.1
2025-02-14T09:58:05+0000 [-] Loaded output engine: jsonlog
2025-02-14T09:58:05+0000 [twisted.scripts._twistd_unix.UnixAppLogger#info] twistd 24.10.0 (/cowrie/cowrie-env/bin/python3 3.11.2) starting up.
2025-02-14T09:58:05+0000 [twisted.scripts._twistd_unix.UnixAppLogger#info] reactor class: twisted.internet.epollreactor.EPollReactor.
2025-02-14T09:58:05+0000 [-] CowrieSSHFactory starting on 2222
2025-02-14T09:58:05+0000 [cowrie.ssh.factory.CowrieSSHFactory#info] Starting factory <cowrie.ssh.factory.CowrieSSHFactory object at 0xffff7f752c10>
2025-02-14T09:58:05+0000 [-] Generating new RSA keypair...
2025-02-14T09:58:05+0000 [-] Generating new ECDSA keypair...
2025-02-14T09:58:05+0000 [-] Generating new ed25519 keypair...
2025-02-14T09:58:05+0000 [-] Ready to accept SSH connections
2025-02-14T09:58:06+0000 [cowrie.ssh.factory.CowrieSSHFactory] No moduli, no diffie-hellman-group-exchange-sha1
...
...
...
2025-02-14T09:58:07+0000 [HoneyPotSSHTransport,10,192.168.65.1] login attempt [b'adventuress'/b'1978'] failed
2025-02-14T09:58:07+0000 [cowrie.ssh.userauth.HoneyPotSSHUserAuthServer#debug] b'adventure' trying auth b'password'
2025-02-14T09:58:07+0000 [HoneyPotSSHTransport,8,192.168.65.1] Could not read etc/userdb.txt, default database activated
2025-02-14T09:58:07+0000 [HoneyPotSSHTransport,8,192.168.65.1] login attempt [b'adventure'/b'hard'] failed
2025-02-14T09:58:07+0000 [cowrie.ssh.userauth.HoneyPotSSHUserAuthServer#debug] b'adventurer' trying auth b'password'
2025-02-14T09:58:07+0000 [HoneyPotSSHTransport,7,192.168.65.1] Could not read etc/userdb.txt, default database activated
2025-02-14T09:58:07+0000 [HoneyPotSSHTransport,7,192.168.65.1] login attempt [b'adventurer'/b'england'] failed
2025-02-14T09:58:08+0000 [cowrie.ssh.userauth.HoneyPotSSHUserAuthServer#debug] b'adventitious' failed auth b'password'
...
...
...
2025-02-14T09:58:08+0000 [HoneyPotSSHTransport,12,192.168.65.1] login attempt [b'adventitia'/b'zxc123'] failed
2025-02-14T09:58:08+0000 [cowrie.ssh.userauth.HoneyPotSSHUserAuthServer#debug] b'root' trying auth b'password'
2025-02-14T09:58:08+0000 [HoneyPotSSHTransport,13,192.168.65.1] Could not read etc/userdb.txt, default database activated
2025-02-14T09:58:08+0000 [HoneyPotSSHTransport,13,192.168.65.1] login attempt [b'root'/b'123456789q'] succeeded
2025-02-14T09:58:08+0000 [HoneyPotSSHTransport,13,192.168.65.1] Initialized emulated server as architecture: linux-x64-lsb
2025-02-14T09:58:08+0000 [cowrie.ssh.userauth.HoneyPotSSHUserAuthServer#debug] b'root' authenticated with b'password'
</pre>

### If running against your macOS ssh server, 

- Comment out following lines:
    int port = 2222; // Set custom SSH port here
    ssh_options_set(session, SSH_OPTIONS_PORT, &port);

- make
- ./hydra_ssh

<pre>
MacBook-Air-2:hydra-bruteforce anish$ ./hydra_ssh 
[-] Failed: adverbial:polina
[-] Failed: adventurous:01011980
[-] Failed: adverb:wildcat
[-] Failed: adversaria:freepass
[-] Failed: adventurism:cowrie
[-] Failed: adventurer:england
[-] Failed: adventure:hard
[-] Failed: adventuress:1978
[-] Failed: adventuresome:brazil
[-] Failed: adventitious:crazy
[-] Failed: advent:avatar
[-] Failed: adventist:alpha
[-] Failed: adventitia:zxc123
[-] Failed: root:123456789q
[-] Failed: advection:wombat
[-] Failed: advantage:classic
[-] Failed: advantageous:raptor
[-] Failed: advancement:darkside
[-] Failed: advance:spiderman
</pre>

- log stream --predicate 'process == "sshd"' --info | grep "Failed"
<pre>
MacBook-Air-2:hydra-bruteforce anish$ log stream --predicate 'process == "sshd"' --info | grep "Failed"
2025-02-14 15:25:06.686157+0530 0x67eae    Info        0x0                  39052  0    sshd: Failed password for invalid user adventuress from ::1 port 60031 ssh2
2025-02-14 15:25:06.707757+0530 0x67eb2    Info        0x0                  39054  0    sshd: Failed password for invalid user adventuresome from ::1 port 60033 ssh2
2025-02-14 15:25:06.752890+0530 0x67eba    Info        0x0                  39056  0    sshd: Failed password for invalid user adventurer from ::1 port 60035 ssh2
2025-02-14 15:25:06.851410+0530 0x67ec0    Info        0x0                  39058  0    sshd: Failed password for invalid user adventure from ::1 port 60037 ssh2
2025-02-14 15:25:07.300911+0530 0x67ed0    Info        0x0                  39062  0    sshd: Failed password for invalid user adventitious from ::1 port 60039 ssh2
2025-02-14 15:25:09.602436+0530 0x67eda    Info        0x0                  39065  0    sshd: Failed password for invalid user adventitia from ::1 port 60041 ssh2
2025-02-14 15:25:09.807526+0530 0x67ee0    Info        0x0                  39067  0    sshd: Failed password for invalid user adventist from ::1 port 60043 ssh2
2025-02-14 15:25:10.044788+0530 0x67ee6    Info        0x0                  39069  0    sshd: Failed password for invalid user advent from ::1 port 60045 ssh2
2025-02-14 15:25:10.301038+0530 0x67eec    Info        0x0                  39071  0    sshd: Failed password for invalid user advection from ::1 port 60047 ssh2
2025-02-14 15:25:10.804924+0530 0x67ef3    Info        0x0                  39073  0    sshd: Failed password for root from ::1 port 60051 ssh2
2025-02-14 15:25:12.234544+0530 0x67f8a    Info        0x0                  39168  0    sshd: Failed password for invalid user advantageous from ::1 port 60053 ssh2
2025-02-14 15:25:12.853405+0530 0x67f91    Info        0x0                  39170  0    sshd: Failed password for invalid user advantage from ::1 port 60057 ssh2
2025-02-14 15:25:13.285978+0530 0x67f98    Info        0x0                  39172  0    sshd: Failed password for invalid user advancement from ::1 port 60059 ssh2
2025-02-14 15:25:13.467504+0530 0x67f9e    Info        0x0                  39174  0    sshd: Failed password for invalid user advanced from ::1 port 60061 ssh2
2025-02-14 15:25:14.240056+0530 0x67fb0    Info        0x0                  39177  0    sshd: Failed password for invalid user advance from ::1 port 60063 ssh2
2025-02-14 15:25:56.684690+0530 0x68328    Info        0x0                  39565  0    sshd: Failed password for invalid user adverbial from ::1 port 60093 ssh2
...
...
...
</pre>
