#!/usr/bin/python3
"""number of rescue boats module"""

from typing import List


def numRescueBoats(people: List[int], limit: int) -> int:
    """perform the minimum number of rescue boats to save all people"""

    people.sort()
    max_boats = 0
    first = 0
    last = len(people) - 1
    
    while (first <= last):
        if (first == last):
            max_boats += 1
            break
        if (people[first] + people[last] <= limit):
            first += 1

        last -= 1
        max_boats += 1
    
    return max_boats
