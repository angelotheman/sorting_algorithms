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


int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot_value;

	pivot_value = array[high];
	i = (low - 1);

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot_value)
		{
			i++;
			swap(&array[i], &array[j]);
		}
		print_array(array, size);
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}


void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = partition(array, low, high, size);

		quick_sort_recursion(array, low, pivot_idx - 1, size);

		quick_sort_recursion(array, pivot_idx + 1, high, size);
	}
}

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursion(array, 0, size - 1, size);
}
