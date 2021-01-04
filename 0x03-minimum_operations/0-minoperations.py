#!/usr/bin/python3
"""
Assume we have a single character 'H'.
We can execute only 2 operations 'Copy' and 'Past'.
The function above helps us to compute the minimum operation
to reach the a given 'n' of the character 'H'.
"""


def minOperations(n):
    """this function calculates the factorization of the n
    and returns the sum of that array"""

    f = []
    i = 2

    if not isinstance(n, int) or n < 2:
        return 0

    while i <= n:
        if n % i == 0:
            f.append(i)
            n //= i
        else:
            i += 1
    return sum(f)
