#!/usr/bin/python3
"""calculates the fewest number of operations
   needed to result in exactly n H characters
"""


def minOperations(n):
    """returns number of operations copy and paste"""
    if n <= 1 or type(n) != int:
        return 0
    if n == 2:
        return 2
    max_div = n - 1
    cp = 2
    dh = 1
    H = 2
    while H < n:
        if n % H == 0:
            dh = H
            cp += 2
            H = H + dh
        else:
            cp += 1
            H = H + dh
    return cp
