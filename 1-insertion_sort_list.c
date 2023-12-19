#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * oreder using the insertion sort algorithm
 *
 * @list: Pointer to pointer to a doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *pt, *curr, *prev;

	if (!list || !*list)
		return;

	for (pt = (*list)->next; pt != NULL; pt = pt->next)
	{
		curr = pt;
		prev = curr->prev;

		while (prev != NULL && prev->n > curr->n)
		{
			swap_node(prev, curr);
			print_list(*list);
			prev = prev->prev;
			curr = curr->prev;
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
