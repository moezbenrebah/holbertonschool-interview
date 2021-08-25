#include "sort.h"

/**
 * swap - swap 2 elements
 * @a: integer
 * @b: integer
 *
 * Return: void
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


/**
 * heap_max - build a heap
 * @arr: a pointer to the 1st element of the array
 * @a: integer
 * @b: integer
 * @size: the array size
 *
 * Return: void
 */

void heap_max(int *arr, int a, int b, int size)
{
	int index, right, left;

	right = 2 * b + 2;
	left = 2 * b + 1;
	index = b;

	if (right < a && arr[right] > arr[index])
		index = right;
	if (left < a && arr[left] > arr[index])
		index = left;
	if (index != b)
	{
		swap(&arr[b], &arr[index]);
		print_array(arr, size);
		heap_max(arr, a, index, size);
	}
}


/**
 * heap_sort - sorting a heap
 * @array: array of integers
 * @size: the array size
 *
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heap_max(array, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i != 0)
		{
			print_array(array, size);
			heap_max(array, i, 0, size);
		}
	}
}


























