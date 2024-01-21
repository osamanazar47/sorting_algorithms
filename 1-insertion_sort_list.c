#include "sort.h"
/**
 * swap_n - a function that swaps two nodes
 * @head: a pointer to the head of the list
 * @node1: the first node
 * @node2: the second node
 */
void swap_n(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
/**
 * insertion_sort_list - a function that sorts
 * a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		insert = current->prev;
		while (insert != NULL && current->n < insert->n)
		{
			swap_n(list, &insert, current);
			print_list((const listint_t *)*list);
		}
	}
}
