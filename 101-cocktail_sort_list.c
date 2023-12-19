#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * oreder using the Cocktail sort algorithm
 *
 * @list: Pointer to pointer to a doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head = *list, *forward, *backward;
	int SWAP = 1;

	if (!list || !*list)
		return;

	while (SWAP)
	{
		SWAP = 0;

		forward = head;
		while (forward && forward->next)
		{
			if (forward->n > forward->next->n)
			{
				swap_node(forward, forward->next);
				print_list(*list);
				SWAP = 1;
			}
			forward = forward->next;
		}

		backward = forward;
		while (backward && backward->prev)
		{
			if (backward->n < backward->prev->n)
			{
				swap_node(backward, backward->prev);
				print_list(*list);
				SWAP = 1;
			}
			backward = backward->prev;
		}
	}
}

/**
 * swap_node - swaps two nodes in a dubly linked list
 *
 * @x: pointer to the first node
 * @y: pointer to the second node
 */
void swap_node(listint_t *x, listint_t *y)
{
	int tmp, *change;

	if (!x || !y || x == y)
		return;

	tmp = x->n;
	change = (int *)&x->n;
	*change = y->n;
	change = (int *)&y->n;
	*change = tmp;
}
