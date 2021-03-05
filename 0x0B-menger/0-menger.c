#include "menger.h"


/**
 * character_to_draw - check whether a space or hash to draw
 * @x: x axis index
 * @y: y axis index
 *
 * Return: 1 if it is a space, otherwise 0 for hash ('#')
 */

int character_to_draw(int x, int y)
{
	while (x != 0 && y != 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (1);

		x /= 3;
		y /= 3;
	}

	return (0);
}


/**
 * menger - draw a 2d menger sponge
 * @level: number of level to draw
 *
 * Return: Void
 */

void menger(int level)
{
	int i, j;

	int size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (character_to_draw(i, j) != 0)
			{
				putchar(' ');
			}
			else
				putchar('#');

		}
		putchar('\n');
	}
}
