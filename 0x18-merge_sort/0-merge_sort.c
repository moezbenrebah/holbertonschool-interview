#include "sort.h"


/**
 * divide_compare - divide and compare sublists between each other
 * @Arr: pointer to the first array item
 * @size: size of the array
 * @mid: Middle index
 * @temp: pointer to the first new array to store compared array items
 * Return: nothing
 */

void divide_compare(int *Arr, int size, int mid, int *temp)
{
	int m, n, l;

	printf("Merging...\n[left]: ");
	print_array(Arr, mid);
	printf("[right]: ");
	print_array(Arr + mid, size - mid);
	for (m = 0, n = mid, l = 0; l < size; l++)
	{

		if (n == size)
		{
			temp[l] = Arr[m];
			m++;
		}
		else if (m == mid)
		{
			temp[l] = Arr[n];
			n++;
		}
		else if (Arr[n] < Arr[m])
		{
			temp[l] = Arr[n];
			n++;
		}
		else
		{
			temp[l] = Arr[m];
			m++;
		}
	}
	for (m = 0; m < size; m++)
	{
		Arr[m] = temp[m];
	}
	printf("[Done]: ");
	print_array(temp, size);
}


/**
 * merge - sort each sublist and compare them to sort the entire array
 * @Arr: pointer to the first array item
 * @size: size of the array
 * @temp: pointer to the first new array to store the compared items
 * Return: nothing
 */

void merge(int *Arr, size_t size, int *temp)
{
	int mid;

	if (size < 2)
		return;
	mid = size / 2;
	merge(Arr, mid, temp);
	merge(Arr + mid,  size - mid, temp);
	divide_compare(Arr, size, mid, temp);
}


/**
 * merge_sort - merge an array of integers in ascending order
 * @array: pointer to the first array item
 * @size: size of the array
 * Return: nothing
 */

void merge_sort(int *array, size_t size)
{
	int *temp = NULL;

	if (!array || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	merge(array, size, temp);
	free(temp);
}
