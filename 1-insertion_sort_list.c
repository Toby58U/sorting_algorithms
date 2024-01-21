#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @y1: A pointer to the first node to swap.
 * @y2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **y1, listint_t *y2)
{
	(*y1)->next = y2->next;
	if (y2->next != NULL)
		y2->next->prev = *y1;
	y2->prev = (*y1)->prev;
	y2->next = *y1;
	if ((*y1)->prev != NULL)
		(*y1)->prev->next = y2;
	else
		*h = y2;
	(*y1)->prev = y2;
	*y1 = y2->prev;
}

/**
 * insertion_sort_list - Sorts doubly linked list using the insertion sort.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		current = iter->prev;
		while (current != NULL && iter->n < current->n)
		{
			swap_nodes(list, &current, iter);
			print_list((const listint_t *)*list);
		}
	}
}
