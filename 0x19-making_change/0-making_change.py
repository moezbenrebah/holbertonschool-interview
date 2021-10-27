#!/usr/bin/python3
""" MakeChange module"""


def makeChange(coins, total):
    """
    find the minimum number of coins that meets the total number
    """
    if total == 0:
        return 0
    if not coins or min(coins) > total:
        return -1

    coins.sort()
    i = len(coins) - 1
    arr = []
    while i >= 0:
        if sum(coins) < total:
            return -1
        if coins[i] <= total:
            total -= coins[i]
            arr.append(coins[i])
        i -= 1

    return len(arr)
