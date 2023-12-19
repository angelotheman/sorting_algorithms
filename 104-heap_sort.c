#include "sort.h"

void swap(int *var1, int *var2);
void heapify(int *array, size_t size, size_t n);

/**
 * heap_sort - sorts an integer using the heap sort algorithm
 * @array: unsorted array
 * @size: size of array
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
    size_t i;

    for (i = size / 2; i >= 1; i--)
        heapify(array, size, i);

    for (i = size; i >= 1; i--)
    {
        swap(&array[i], &array[1]);
        heapify(array, size, 1);
    }
}


/**
 * heapify - sorts elements in a heap tree section
 * @array: array
 * @size: size of array
 * @n: position of element in tree
 * Return: void
 */

void heapify(int *array, size_t size, size_t n)
{
    size_t largest_index, left_child, right_child;

    largest_index = n;
    left_child = 2 * n;
    right_child = 2 * n + 1;

    if (left_child <= size && array[largest_index] < array[left_child])
        largest_index = left_child;

    if (right_child <= size && array[largest_index] < array[right_child])
        largest_index = right_child;

    if (largest_index != n)
    {
        swap(&array[largest_index], &array[n]);
        heapify(array, size, largest_index);
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