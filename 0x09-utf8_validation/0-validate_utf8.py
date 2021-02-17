#!/usr/bin/python3
"""
a method that determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    """
    This method return True if the given data is a valid utf-8
    otherwise false.
    """
    i = 0
    while i < len(data):
        n = data[i]
        shift = 7
        num_bits_set = 0
        # Extracting the leftmost bit
        while (n >> shift) & 1 and num_bits_set < 5:
            shift -= 1
            num_bits_set += 1

        if num_bits_set == 0:
            i += 1
        elif num_bits_set == 1 or num_bits_set > 4\
                or num_bits_set > len(data) - i:
            return False
        else:
            i += 1
            for _ in range(num_bits_set-1):
                n = data[i]
                # Checking if the two leftmost bits are 10
                if not (((n >> 7) & 1) and ~((n >> 6) & 1)):
                    return False
                i += 1
    return True
