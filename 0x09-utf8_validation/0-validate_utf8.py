#!/usr/bin/python3
"""method that determines if a
   given data set represents
   a valid UTF-8 encoding"""


def validUTF8(data):
    """Return: True if data is a valid
       UTF-8 encoding, else return False"""
    bites = 0
    mask2 = 1 << 6
    for ele in data:
        mask1 = 1 << 7
        if bites == 0:
            while ele & mask1:
                bites += 1
                mask1 = mask1 >> 1
            if bites > 4 or bites == 1:
                return False
            if bites == 0:
                continue
        else:
            if not (ele & mask1 and not (ele & mask2)):
                return False
        bites -= 1
    return bites == 0
