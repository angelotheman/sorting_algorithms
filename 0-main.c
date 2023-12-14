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
	int sarray[] = {100, 48, 64, 85, 56, 73, 18, 33, 99, 83};
	size_t n = sizeof(sarray) / sizeof(sarray[0]);

	print_array(sarray, n);
	printf("\n");
	bubble_sort(sarray, n);
	printf("\n");
	print_array(sarray, n);
	return (0);
}

