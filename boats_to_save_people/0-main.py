#!/usr/bin/python3
"""main test file"""

from save_boats import numRescueBoats


if __name__ == '__main__':
    array = [1, 2, 3, 3]
    limit = 3
    print(numRescueBoats(array, limit))
    array = [1, 2, 3, 3, 2, 2, 1]
    limit = 4
    print(numRescueBoats(array, limit))
    array = [1, 2, 3,]
    limit = 4
    print(numRescueBoats(array, limit))
    array = [1, 2, 3, 3, 2, 2, 1]
    limit = 3
    print(numRescueBoats(array, limit))
