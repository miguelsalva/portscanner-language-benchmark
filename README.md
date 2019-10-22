# Port Scanner Language Benchmark

This repository benchmarks a simple TCP port scanner written in C and Python, in order to know which language is better to write such application in future developments.


Origin of the code:
* C: An old paper named _Coding a TCP Connect Port Scanner: Step by Step_ from truncode security development
* Python: HowTo/Sockets from the official Python wiki at https://wiki.python.org/moin/HowTo/Sockets
<br>

### Benchmark results

This benchmark has been performed using the _time_ command in Linux to get the run time:

    miguel@minidell:~/dev$ time ./portscanner 192.168.1.1
    Port 23 is open
    Port 53 is open
    Port 80 is open
    Port 443 is open
    
    real	0m2,016s
    user	0m0,000s
    sys	0m0,090s


Also, three different port ranges have been used:
1. System ports: 0-1023
2. Registered ports: 1024-49151
3. Private ports: 49152-65535 

All scanning have been performed against an internal network host.


Please find below the final results:

Programming Language | System ports time | System+Registered ports time | All ports time
-------------------- | ----------------- | ---------------------------- | --------------
C | 0m2,016s | 1m44,030s | 2m16,991s
Python | 0m2,244s | 1m45,825s | 2m19,512s
<br>

### Contributing 

Please feel free to contribute with any idea or comment.

