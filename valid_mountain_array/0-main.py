#!/usr/bin/python3
"""main file test"""

from valid_mountain import valid_mountain_array


if __name__ == '__main__':
    array = [1,2,5,6,2,1]
    print(valid_mountain_array(array))
    array = [1,2,5,6]
    print(valid_mountain_array(array))
    array = [1,2,2,2,2]
    print(valid_mountain_array(array))
