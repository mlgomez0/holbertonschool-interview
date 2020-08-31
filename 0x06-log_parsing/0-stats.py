#!/usr/bin/python3
""" script that reads stdin line
    by line and computes metrics"""
import sys
import signal


def exit_gracefully(file_size, status_codes):

    print('File size: {}'.format(file_size))
    for k, v in sorted(status_codes.items()):
        print('{}: {}'.format(k, v))
    sys.exit(0)

status_codes = {}
file_size = 0
num = 1
try:
    for line in sys.stdin:
        args = line.split(' ')
        file_size = file_size + int(args[-1])
        if args[-2] in status_codes:
            status_codes[args[-2]] += 1
        else:
            status_codes[args[-2]] = 1
        if num % 10 == 0:
            print('File size: {}'.format(file_size))
            for k, v in sorted(status_codes.items()):
                print('{}: {}'.format(k, v))
        num += 1
except KeyboardInterrupt:
    pass
finally:
    exit_gracefully(file_size, status_codes)
