#!/usr/bin/python3
""" test main """

from move_zeros import moveZeros


if __name__ == '__main__':
    array = [0, 1, 0, 3, 12]
    print(moveZeros(array))
    array = [0, 1, 0, 3, 0, 0, 12]
    print(moveZeros(array))
    array = [0, 0, 0, 0, 0, 12]
    print(moveZeros(array))
    array = [0, 0, 0, 0, 0]
    print(moveZeros(array))
