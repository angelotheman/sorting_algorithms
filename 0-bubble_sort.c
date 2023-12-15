#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *				with bubble sort algorithm
 * @array: array of integers to be sorted
 * @size: size of array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int count_swap;

	for (i = 0; i < size; i++)
	{
		count_swap = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				count_swap = 1;
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
		if (count_swap == 0)
			break;
	}
}

/**
  * swap - swaps the value of variables
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

