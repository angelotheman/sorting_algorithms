#include "sort.h"

/**
 * swap - Performs the swap function
 * a: First arg
 * b: Second arg
 */


void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

size_t partition(int *array, size_t low, size_t high)
{
	size_t i, j;
	int pivot_value;

	pivot_value = array[high];
	i = (low - 1);

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot_value)
		{
			i++;
			swap(&array[i], &array[j]);
		}
		/* print_array(array, high); */
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, high);

	return (i + 1);
}


void quick_sort(int *array, size_t size)
{
	size_t pivot_idx, low, high;

	low = 0;
	high = size - 1;

	if (low < high)
	{
		pivot_idx = partition(array, 0, size - 1);

		quick_sort(array, low, pivot_idx - 1);

		quick_sort(array, pivot_idx + 1, high);
	}
}
