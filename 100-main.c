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
	int array[] = {819, 405, 406, 836, 672, 977, 976, 413, 320, 145, 418, 687, 951, 158, 293, 763, 804, 973, 396, 121};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	shell_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}

