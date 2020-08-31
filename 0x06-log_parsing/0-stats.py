#!/usr/bin/python3
""" script that reads stdin line
    by line and computes metrics"""
import sys


status_codes = {"200":0, "301":0, "400":0, "401":0, "403":0, "404":0, "405":0, "500":0}
file_size = 0
num = 1
try:
    for line in sys.stdin:
        args = line.split(' ')
        file_size = file_size + int(args[-1])
        if args[-2] in status_codes:
            status_codes[args[-2]] += 1
        if num % 10 == 0:
            print('File size: {}'.format(file_size))
            for k, v in sorted(status_codes.items()):
                if v != 0:
                    print('{}: {}'.format(k, v))
        num += 1
except KeyboardInterrupt:
    pass
finally:
    print('File size: {}'.format(file_size))
    for k, v in sorted(status_codes.items()):
        if v != 0:
            print('{}: {}'.format(k, v))
