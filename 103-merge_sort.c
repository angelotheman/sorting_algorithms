#include "sort.h"


/**
 * merge - Build up the merge of sorted arrays
 * @array: Original array
 * @new_array: Duplicate array for building new sorted element
 * @low: Lower bound of array
 * @mid: Midpoint of array
 * @high: Upper bound of array
 */

void merge(int *array, int *new_array, size_t low, size_t mid, size_t high)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n[left]: ");
	print_array(new_array + low, mid - low);
	printf("[right]: ");
	print_array(new_array + mid, high - mid);

	i = low;
	j = mid;
	k = low;

	for (; k < high; k++)
	{
		if (i < mid && (j >= high || new_array[i] <= new_array[j]))
		{
			array[k] = new_array[i];
			i++;
		}
		else
		{
			array[k] = new_array[j];
			j++;
		}
	}

	printf("[Done]: ");
	print_array(array + low, high - low);
}


/**
 * merge_recursion - Recursively divides the array till sorted
 * @array: Array of integer elements
 * @new_array: Duplicate array for the sorting
 * @low: Lower bound of array
 * @high: Upper bound of array
 */

void merge_recursion(int *array, int *new_array, size_t low, size_t high)
{
	size_t mid;

	if (high - low > 1)
	{
		mid = (low + high) / 2;

		merge_recursion(array, new_array, low, mid);

		merge_recursion(array, new_array, mid, high);

		merge(array, new_array, low, mid, high);

		for (mid = low; mid < high; mid++)
			new_array[mid] = array[mid];
	}
}


/**
 * merge_sort - Boiler plate for the merge sort algorithm
 * @array: Array of integer elements
 * @size: Size of the array
 */

void merge_sort(int *array, size_t size)
{
	size_t i = 0;
	int *new_array;

	if (size < 2 || array == NULL)
		return;

	new_array = malloc(sizeof(int) * size);

	if (!new_array)
		return;

	while (i < size)
	{
		new_array[i] = array[i];
		i++;
	}

	merge_recursion(array, new_array, 0, size);

	free(new_array);
}
