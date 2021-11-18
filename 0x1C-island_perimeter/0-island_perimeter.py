#!/usr/bin/python3
"""grid perimeter module"""


def island_perimeter(grid):
    """function to computer perimeter within a 2d array"""

    if grid is None or len(grid) == 0 or len(grid[0]) == 0:
        return 0

    grid_len = len(grid)
    row_len = len(grid[0])
    perimeter = 0

    for i in range(grid_len):
        for j in range(row_len):
            if grid[i][j] == 0:
                continue
            if i == 0 or grid[i-1][j] == 0:
                perimeter += 1
            if i == grid_len - 1 or grid[i+1][j] == 0:
                perimeter += 1
            if j == 0 or grid[i][j-1] == 0:
                perimeter += 1
            if j == row_len - 1 or grid[i][j+1] == 0:
                perimeter += 1

    return perimeter
