#!/usr/bin/python3


def canUnlockAll(boxes):

    if boxes is None and not isinstance(boxes, list) and boxes == []:
        return False
    else:
        for i in range(len(boxes)):
            if not isinstance(i, list):
                return False
            else:
                for j in i:
                    if not isinstance(j, int):
                        return False
                    else:
                        if boxes[i][j] == boxes[i]:
                            return True
                        else:
                            return False
