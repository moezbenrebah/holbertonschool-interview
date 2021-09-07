#!/usr/bin/python3
"""valid mountain sub-array module"""

from typing import List


def valid_mountain_array(arr: List[int]) -> bool:
    """check if an array is a valid mountain"""

    if len(arr) < 3:
        return False

    # initiate the i pointer in the index 1
    i = 1

    while (i < len(arr) and arr[i] > arr[i - 1]):
        i += 1

    # return False if i still equal to its initial value or there's no increasing value
    if (i == 1 or i == len(arr)):
        return False

    while (i < len(arr) and arr[i] < arr[i - 1]):
        i += 1

    return i == len(arr)
