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

/* ---- HELPER FUNCTIONS ---- */
void swap(int *var1, int *var2);

#endif /* SORT_H */
