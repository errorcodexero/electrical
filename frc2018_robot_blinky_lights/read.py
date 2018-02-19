#!/usr/bin/python
import serial
import sys

s = serial.Serial(port = '/dev/ttyS2', baudrate = 9600, parity = serial.PARITY_NONE, timeout = 1)
if s.isOpen():
    s.flush()
    try:
        while True:
            print("running")
            print(s.readline())
    except KeyboardInterrupt:
        s.close()
        sys.exit()
