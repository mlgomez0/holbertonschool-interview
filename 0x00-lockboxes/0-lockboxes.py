#!/usr/bin/python3
"""Determines if all boxes have a key"""


def canUnlockAll(boxes):
    """returns True or False"""
    list_keys = []
    box_stack = boxes[0]
    temp_stack = []
    i = 0
    n = 0

    while len(box_stack) != 0:
        box_open = box_stack.pop()
        if type(box_open) != list:
            if box_open not in list_keys:
                list_keys.append(box_open)
                temp_stack.append(boxes[box_open])
        else:
            for key in box_open:
                if key not in list_keys and key != 0:
                    list_keys.append(key)
                    temp_stack.append(boxes[key])
        if len(box_stack) == 0 and len(temp_stack) != 0:
            box_stack = [row for row in temp_stack]
            temp_stack = []
    list_keys.sort()
    if list_keys[0] == 1:
        i = 1

    while i < len(boxes):
        if i != list_keys[n]:
            return False
        i += 1
        n += 1
    return True
