#ifndef _SANDPILES_H
#define _SANDPILES_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>


void render_grid(int gird[3][3]);
bool checking_grid(int grid[3][3]);
void stable_grid(int grid1[3][3], int grid2[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /* _SANDPILES_H */
