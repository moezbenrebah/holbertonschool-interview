#!/usr/bin/python3

import sys


def printBoard(chessboard):
    """
    Prints the board
    Args:
        board: N*N dimensions chessboard

    Return: nothing
    """
    result = []
    for i in range(N):
        for j in range(N):
            if chessboard[i][j] == 1:
                result.append([i, j])
    print(result)


def check_position(chessboard, row, col):
    """
    Check_position: checks if a queen is attacked by another queen

    Args
    chessboard (list of lists): chessboard with N*N dimensions
    row (int): row position
    col int): column position
    Return:
        boolean
    """
    for i in range(col):
        if chessboard[row][i]:
            return False
    i, j = row, col

    while i >= 0 and j >= 0:
        if chessboard[i][j]:
            return False
        i -= 1
        j -= 1

    i, j = row, col

    while j >= 0 and i < N:
        if chessboard[i][j]:
            return False
        i = i + 1
        j = j - 1

    return True


def backtrack(chessboard, col):
    """
    backtrack: a function to execute backtrack to set queens positions

    Args:
        board (list of lists): chessboard with N*N dimensions
        col (int): column position
    Return:
        boolean
    """
    if col == N:
        printBoard(chessboard)
        return True
    res = False
    for i in range(N):
        if check_position(chessboard, i, col):
            chessboard[i][col] = 1
            res = backtrack(chessboard, col + 1) or res
            chessboard[i][col] = 0

    return res


if __name__ == '__main__':

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    if not sys.argv[1].isdigit():
        print("N must be a number")
        sys.exit(1)

    N = int(sys.argv[1])

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    chessboard = [[0 for j in range(N)] for i in range(N)]
    possilibities = backtrack(chessboard, 0)

