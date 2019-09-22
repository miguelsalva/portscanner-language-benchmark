#!/usr/bin/env python3
import sys
import socket

host = sys.argv[1]
MAXPORT = 1024

s = socket.socket()

for port in range(1,MAXPORT):
    if s.connect_ex((host,port)) == 0:
        print("Port " + str(port) + " is open")

s.close()
