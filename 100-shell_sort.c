#include "sort.h"

/**
 * shell_sort - sorts an array in ascending order using shell sort algorithm's
 *					knuth sequence
 * @array: unsorted array
 * @size: size of array
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	int i;
	size_t j, gap;

	gap = 1;
	while (gap < (size / 3))
		gap = 3 * gap + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (array[i + gap] > array[i])
					break;
				swap(&array[i + gap], &array[i]);
			}
		}
		print_array(array, size);
	}
}


/**
 * swap - swaps the values of two variables
 * @var1: variable 1
 * @var2: variable 2
 * Return: void
 */

void swap(int *var1, int *var2)
{
	int tmp;

	tmp = *var1;
	*var1 = *var2;
	*var2 = tmp;
}

