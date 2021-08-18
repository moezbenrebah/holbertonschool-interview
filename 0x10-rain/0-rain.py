#!/usr/bin/python3
"""rain module"""


def rain(walls):
    """compute the amount of water that it can be stored"""
    size = len(walls)

    if walls == [] or sum(walls) == 0:
        return 0

    start = [0]*size
    end = [0]*size

    water_count = 0

    start[0] = walls[0]
    for i in range(1, size):
        start[i] = max(start[i - 1], walls[i])

    end[size - 1] = walls[size - 1]
    for i in range(size - 2, -1, -1):
        end[i] = max(end[i + 1], walls[i])

    for i in range(0, size):
        water_count += min(start[i], end[i]) - walls[i]

    return water_count
