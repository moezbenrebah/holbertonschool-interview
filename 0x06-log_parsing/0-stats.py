#!/usr/bin/python3
"""A program to parse log files """

import sys


j = 0
size = 0
status_code = {'200': 0, '301': 0, '400': 0, '401': 0,
               '403': 0, '404': 0, '405': 0, '500': 0}
err_code = ['200', '301', '400', '401', '403', '404', '405', '500']
try:
    for line in sys.stdin:
        j += 1
        a = line.split(' ')
        if len(a) > 2:
            size += int(a[-1])
            if a[-2] in status_code:
                status_code[a[-2]] += 1
        if j % 10 == 0:
            print("File size: {}".format(size))
            for error in err_code:
                if status_code[error]:
                    print("{}: {}".format(error, status_code[error]))
except KeyboardInterrupt:
    pass
finally:
    print("File size: {}".format(size))
    for error in err_code:
        if status_code[error]:
            print("{}: {}".format(error, status_code[error]))
