#include "sort.h"

void count_sort(int *array, size_t size, int pos);
int get_max(int *array, size_t size);

/**
 * radix_sort - sorts an array of integers using the radix sort algo
 * @array: unsorted array
 * @size: size of array
 * Return: void
 */

void radix_sort(int *array, size_t size)
{
	int max, pos;

	if (size < 2)
		return;
	max = get_max(array, size);
	printf("max => %d\n", max);
	for (pos = 1; pos / max > 0; pos *= 10)
	{
		count_sort(array, size, pos);
		print_array(array, size);
	}
}


/**
 * get_max -gets the maximum value in an array of integers
 * @array: array of integers
 * @size: size of array
 * Return: max integer
 */

int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}


/**
 * counting_sort - sorts an array of integers in ascending order using
 *				the Counting Sort algorithm
 * @array: unsorted array
 * @size array size
 * Return: void
 */

void count_sort(int *array, size_t size, int pos)
{
	size_t i, c_size;
	int *count, *barray;

	c_size = 10;
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
		count[(array[i] / pos) % 10]++;

	print_array(count, 10);
	for (i = 1; i < c_size; i++)
		count[i] = count[i] + count[i - 1];
	for (i = 0; i < size; i++)
		barray[--count[(array[i] / pos) % 10]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = barray[i];

	free(count);
	free(barray);
}

