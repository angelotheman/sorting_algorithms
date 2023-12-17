#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using
 *				the Counting Sort algorithm
 * @array: unsorted array
 * @size: array size
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	size_t i, c_size;
	int k;
	int *count, *barray;

	k = 0;
	for (i = 0; i < size; i++)
	{
		if (k < array[i])
			k = array[i];
	}

	c_size = k + 1;
	count = malloc(sizeof(int) * c_size);
	if (count == NULL)
		return;
	for (i = 0; i < c_size; i++)
		count[i] = 0;
	barray = malloc(sizeof(int) * size);
	if (barray == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i < c_size; i++)
		count[i] = count[i] + count[i - 1];

	print_array(count, c_size);

	for (i = 0; i < size; i++)
		barray[--count[array[i]]] = array[i];

	for (i = 0; i < size; i++)
		array[i] = barray[i];

	free(count);
	free(barray);
}

