#!/usr/bin/python3
"""A method that determines if all the boxes can be opened."""


def canUnlockAll(boxes):
    """
    Represent a method to determine if a sub_list has a key
    for the next sub_list
    """

    if not isinstance(boxes, list) or boxes is None:
        return False

    if boxes[0] == []:
        return False

    opened_sub_list = [0]
    for i in range(len(boxes)):
        for j in boxes[i]:
            if not isinstance(j, int):
                return False
            else:
                if j not in opened_sub_list and j < len(boxes) and j != i:
                    opened_sub_list.append(j)
    if len(opened_sub_list) == len(boxes):
        return True
    return False
