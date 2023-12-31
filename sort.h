#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* ---- PRINT FUNCTIONS ----- */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/* ---- SORT FUNCTIONS ------ */
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void bitonic_sort(int *array, size_t size);

/* ---- HELPER FUNCTIONS ---- */
void swap(int *var1, int *var2);
int partition(int *array, int low, int high, size_t size);
void quick_sort_recursion(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t);

/* -- MERGE SORT FUNCTIONS -- */
void merge_recursion(int *array, int *new_array, size_t low, size_t high);
void merge(int *array, int *new_array, size_t low, size_t mid, size_t high);

#endif /* SORT_H */
