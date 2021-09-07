#!/usr/bin/python3
"""move zeros module"""

from typing import List


def moveZeros(arr: List[int]) -> List[int]: 
    """move zeros to end of the array"""

    j = 0
    for i in arr:
        if (i != 0):
            arr[j] = i
            j += 1

    for k in range(j, len(arr)):
        arr[k] = 0

    return arr
