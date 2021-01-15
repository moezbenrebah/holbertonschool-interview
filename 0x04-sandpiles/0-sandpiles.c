#include "sandpiles.h"


/**
 * render_grid - function to render the grid
 * @grid: integers mutlidimensioanl array to render
 *
 * Return: Nothing
 */

void render_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}


/**
 * checking_grid - function to check if the grid is stable or not
 * @grid: integer multidimensional array to check
 *
 * Return: true if stable, otherwise false
 */

bool checking_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (false);

		}
	}
	return (true);
}


/**
 * stable_grid - function to make every cells in a given grid contains
 * no more than 3 grains
 * @grid1: integers mutlidimensioanl array
 * @grid2: integers mutlidimensioanl array
 *
 * Return: Nothing
 */

void stable_grid(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid2[i][j] = grid1[i][j];
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{

			if (grid2[i][j] >= 4)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if (i >= 1)
					grid1[i - 1][j] += 1;
				if (i <= 1)
					grid1[i + 1][j] += 1;
				if (j >= 1)
					grid1[i][j - 1] += 1;
				if (j <= 1)
					grid1[i][j + 1] += 1;
			}
		}
	}
}


/**
 * sandpiles_sum - function to compute the sum of two sandpiles
 * @grid1: integers mutlidimensioanl array
 * @grid2: integers mutlidimensioanl array
 *
 * Return: Nothing
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int new_grid[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	while (!checking_grid(grid1))
	{
		render_grid(grid1);
		stable_grid(grid1, new_grid);
	}
}
