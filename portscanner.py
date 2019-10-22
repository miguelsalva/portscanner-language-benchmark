#!/usr/bin/env python3
#
# FILE: portscanner.py
# AUTHOR: Miguel Salvá
# ABSTRACT: Simple TCP port scanner written in Python to perform a benchmark

import sys
import socket

host = sys.argv[1]
MIN_PORT= 0
MAX_PORT = 65535 
# System ports: 0-1023
# Registered ports: 1024-49151
# Private ports: 49152-65535 


for port in range(MIN_PORT,MAX_PORT):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    if s.connect_ex((host,port)) == 0:
        print("Port " + str(port) + " is open")
    s.close()
