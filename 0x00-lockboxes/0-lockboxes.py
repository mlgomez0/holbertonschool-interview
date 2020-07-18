#!/usr/bin/python3
"""Determines if all boxes have a key"""


def canUnlockAll(boxes):
    """returns True or False"""
    if len(boxes) == 0:
        return False
    if len(boxes) == 1:
        return True
    if len(boxes[0]) == 0:
        return False
    list_keys = [x for x in boxes[0] if x != 0 and x < len(boxes)]

    for i in list_keys:
        if boxes[i]:
            box = boxes[i]
            for j in box:
                if j not in list_keys and j != 0 and j < len(boxes):
                    list_keys.append(j)
    if len(list_keys) != 0:
        list_keys.sort()
        key = 1
        while key <= len(list_keys):
            if key != list_keys[key-1]:
                return False
            key += 1
        if key == len(boxes):
            return True
    return False
