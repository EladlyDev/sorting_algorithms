#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 *
 * @array: pointer to the array to be sorted
 * @size: the size of the @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, smallest, swap_bol = 0;

	if (!array || !size)
		return;

	for (i = 0; i < size; i++)
	{
		smallest = i;
		for (j = i; j < size; j++)
			if (array[j] < array[smallest])
			{
				smallest = j;
				swap_bol = 1;
			}

		if (swap_bol)
		{
			swap(&array[i], &array[smallest]);
			print_array(array, size);
			swap_bol = 0;
		}
	}
}

/**
 * swap - swaps two values
 * @x: the x value
 * @y: the y value
 **/
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
