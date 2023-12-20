#include "sort.h"

void cocktail_sort_list_reverse(listint_t **list, listint_t **curr);
/**
 * cocktail_sort_list - sorts a doubly linked list using the
 *			cocktail sort algorithm
 * @list: doubly linked list to be sorted
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *next, *tmp, *loop_next;
	int swapped = 1;

	if (list == NULL)
		return;
	curr = *list;
	while (swapped)
	{
		swapped = 0;
		while (curr->next != NULL)
		{
			loop_next = curr->next;
			if (curr->n > curr->next->n)
			{
				tmp = curr;
				prev = tmp->prev;
				next = tmp->next;

				if (prev != NULL)
					prev->next = next;
				if (prev == NULL)
					*list = next;
				next->prev = prev;
				tmp->next = next->next;
				if (tmp->next != NULL)
					next->next->prev = tmp;
				tmp->prev = next;
				next->next = tmp;
				print_list(*list);
				swapped = 1;
			}
			curr = loop_next;
		}
		if (swapped == 0)
			break;
		cocktail_sort_list_reverse(list, &curr);
	}
}

/**
 * cocktail_sort_list_reverse - traverses in reverse while sorting
 *				a doubly linked list using the
 *				cocktail sort algorithm
 * @list: doubly linked list to be sorted
 * @curr: current position in linked list
 * Return: void
 */

void cocktail_sort_list_reverse(listint_t **list, listint_t **curr)
{
	listint_t *prev, *next, *tmp, *loop_next;

	while ((*curr)->prev != NULL)
	{
		loop_next = (*curr)->prev;
		if ((*curr)->n < (*curr)->prev->n)
		{
			tmp = *curr;
			prev = tmp->prev;
			next = tmp->next;

			if (next != NULL)
				next->prev = prev;
			if (prev->prev != NULL)
				prev->prev->next = tmp;
			tmp->next = prev;
			tmp->prev = prev->prev;
			if (tmp->prev == NULL)
				*list = tmp;
			prev->prev = tmp;
			prev->next = next;
			print_list(*list);
		}
		*curr = loop_next;
	}
}
