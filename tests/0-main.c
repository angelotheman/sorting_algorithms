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
	int sarray[] = {1, 4, 6, 8, 15, 19, 20, 33, 56, 83};
	size_t n = sizeof(sarray) / sizeof(sarray[0]);

	print_array(sarray, n);
	printf("\n");
	bubble_sort(sarray, n);
	printf("\n");
	print_array(sarray, n);
	return (0);
}

