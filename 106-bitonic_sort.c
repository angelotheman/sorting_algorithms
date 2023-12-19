#include "sort.h"

void swap(int *var1, int *var2);
void heapify(int *array, size_t o_size, size_t size, size_t n);

/**
 * heap_sort - sorts an integer using the heap sort algorithm
 * @array: unsorted array
 * @size: size of array
 * Return: void
 */

void bitonic_sort(int *array, size_t size)
{
	size_t i;

	if (size < 2)
		return;

	for (i = size / 2; i >= 1; i--)
		heapify(array, size, size, i);

	for (i = size; i >= 1; i--)
	{
		if (&array[i - 1] != &array[0])
		{
			swap(&array[i - 1], &array[0]);
			print_array(array, size);
		}
		heapify(array, size, i, 1);
	}
}


/**
 * heapify - sorts elements in a heap tree section
 * @array: array
 * @o_size: original size of array
 * @size: size of array
 * @n: position of element in tree
 * Return: void
 */

void heapify(int *array, size_t o_size, size_t size, size_t n)
{
	size_t largest_index, left_child, right_child;

	largest_index = n;
	left_child = 2 * n;
	right_child = 2 * n + 1;

	if (left_child < size && array[largest_index - 1] < array[left_child - 1])
		largest_index = left_child;

	if (right_child < size && array[largest_index - 1] < array[right_child - 1])
		largest_index = right_child;

	if (largest_index != n)
	{
		swap(&array[largest_index - 1], &array[n - 1]);
		print_array(array, o_size);
		heapify(array, o_size, size, largest_index);
	}
}

/**
 * swap - swaps the values of two variables
 * @var1: first variable
 * @var2: second variable
 * Return: void
 */

void swap(int *var1, int *var2)
{
	int tmp;

	tmp = *var1;
	*var1 = *var2;
	*var2 = tmp;
}
