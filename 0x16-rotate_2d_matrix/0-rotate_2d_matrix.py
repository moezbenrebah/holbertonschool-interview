#!/usr/bin/python3
"""rotate 2D matrix module"""


def rotate_2d_matrix(matrix):
    """
    the function rotate a 2D matrix by transpose sublists items
    and then reverse its positions
    """
    n = len(matrix)

    for i, line in enumerate(matrix):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    for line in matrix:
        line.reverse()
