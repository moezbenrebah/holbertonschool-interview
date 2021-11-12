#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm implement the LSD radix sort algorithm
 * @arr: the array to sort
 * @size: size of the array
 * Return: Nothing
 */
void radix_sort(int *arr, size_t size)
{
	int i, max_item;

	if (size < 2)
		return;
	max_item = getMax(arr, size);
	for (i = 1; max_item / i > 0; i *= 10)
	{
		counting(arr, size, i);
		print_array(arr, size);
	}
}

/**
 * getMax - gets the max number in an array
 * @arr: array to search
 * @size: size of the array
 * Return: the biggest number in the array
 */
int getMax(int *arr, size_t size)
{
	size_t i;
	int max_item = 0;

	for (i = 0; i < size; i++)
	{
		if (arr[i] > max_item)
			max_item = arr[i];
	}
	return (max_item);
}

/**
 * counting - counting sort of the array
 * @arr: the array to sort
 * @size: size of the array
 * @exp: digit to count around
 * Return: Nothing
 */
void counting(int *arr, int size, int exp)
{
	int *result = malloc(sizeof(int) * size);
	int i;
	int count[10] = {0};

	if (!result)
		return;
	for (i = 0; i < size; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		result[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		arr[i] = result[i];
	free(result);
}
