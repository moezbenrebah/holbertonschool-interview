#include "slide_line.h"

/**
 * slide_direction - function to slide integers to right or left direction
 * @line: a pointer to a given array of integers
 * @size: the array size
 * @direction: side from which integers slide
 *
 * Return: Void
 */

void slide_direction(int *line, size_t size, int direction)
{
	int a, b;

	if (direction == SLIDE_RIGHT)
	{
		for (a = (int)size - 1; a >= 0; a--)
		{
			for (b = a - 1; b >= 0; b--)
			{
				if (line[a] == 0 && line[b] != 0)
				{
					line[a] = line[b];
					line[b] = 0;
				}
			}
		}
	}

	if (direction == SLIDE_LEFT)
	{
		for (a = 0; a < (int)size - 1; a++)
		{
			for (b = a + 1; b < (int)size; b++)
			{
				if (line[a] == 0 && line[b] != 0)
				{
					line[a] = line[b];
					line[b] = 0;
				}
			}
		}
	}
}


/**
 * slide_merge - function to merge two integers has the same value
 * @line: a pointer to a given array of integers
 * @size: the array size
 * @direction: side from which integers slide
 *
 * Return: Void
 */

void slide_merge(int *line, size_t size, int direction)
{
	int i;

	if (direction == SLIDE_RIGHT)
	{
		for (i = (int)size - 1; i >= 0; i--)
		{
			if (line[i] == line[i - 1])
			{
				line[i] = line[i] * 2;
				line[i - 1] = 0;
			}
		}
	}
	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < (int)size - 1; i++)
		{
			if (line[i] == line[i + 1])
			{
				line[i] = line[i] * 2;
				line[i + 1] = 0;
			}
		}
	}
}


/**
 * slide_line - function that slides and merges an array of integers
 * @line: a pointer to a given array of integers
 * @size: the array size
 * @direction: side from which integers slide
 *
 * Return: 1 if it succeded, otherwise 0
 */

int slide_line(int *line, size_t size, int direction)
{

	if (!line)
		return (0);

	if (direction != SLIDE_RIGHT && direction != SLIDE_LEFT)
		return (0);


	slide_direction(line, size, direction);
	slide_merge(line, size, direction);
	slide_direction(line, size, direction);

	return (1);
}
