#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order using the insertion sort algorithm
 * @list: head of a doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *next, *tmp, *loop_next;

	curr = *list;
	while (curr != NULL && curr->next != NULL)
	{
		loop_next = curr->next;
		if (curr->n > curr->next->n)
		{
			/* swap current and next */
			tmp = curr;
			while (tmp != NULL && tmp->n > tmp->next->n)
			{
				prev = tmp->prev;
				next = tmp->next;

				/* if previous node is not NULL
				   set next pointer of previous node to next node */
				if (prev != NULL)
					prev->next = next;
				/* if previous node is NULL
				   set head of list to next node */
				if (prev == NULL)
					*list = next;
				next->prev = prev;
				tmp->next = next->next;
				if (tmp->next != NULL)
					next->next->prev = tmp;
				tmp->prev = next;
				next->next = tmp;
				print_list(*list);
				tmp = prev;
			}
		}
		curr = loop_next;
	}
}



