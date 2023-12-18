#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * oreder using the insertion sort algorithm
 *
 * @list: Pointer to pointer to a doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *pt, *current, *prev;

	pt = (*list)->next;
	while (pt != NULL)
	{
		current = pt;
		prev = current->prev;

		while (prev->n > current->n)
		{
			swap_node(left->next, left);
			left = left->prev;
		}
	}
}
/**
 * 5, 2, 1, 0
 * 2, 5, 1, 0
 *
 * 2, 1, 5, 0
 * 1, 2, 5, 0
 *
 * 1, 2, 0, 5
 * 1, 0, 2, 5
 * 0, 1, 2, 5
 *
 * 1: Iterate from i = 1 to size - 1
 * 2: j = i - 1
 * 3: WHILE j >= 0 AND array[j] > key
 * 4: 	swap(array[j + 1], array[j])
 */
