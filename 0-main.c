#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	int sarray[] = {1, 4, 9, 11, 13, 25, 69, 73, 86, 97};
	size_t n = sizeof(sarray) / sizeof(sarray[0]);

	print_array(array, n);
	print_array(sarray, n);
	printf("\n");
	bubble_sort(sarray, n);
	printf("\n");
	print_array(sarray, n);
	return (0);
}

