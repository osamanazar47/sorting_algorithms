#include "sort.h"
/**
 * insertion_sort_list - a function that sorts
 * a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			prev = temp->prev;
			next = temp->next;

			if (prev->prev != NULL)
				prev->prev->next = temp;
			temp->prev = prev->prev;
			temp->next = prev;
			prev->prev = temp;
			prev->next = next;
			if (next != NULL)
				next->prev = prev;
			if (temp->prev == NULL)
				*list = temp;
		}
		current = current->next;
		print_list(*list);
	}
}
