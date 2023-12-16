#include "sort.h"

/**
 * quick_sort - sorts the list
 * @array: the array to be sorted
 * @size: the length of the @array
 **/
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	quick(array, 0, size - 1, size);
}


/**
 * quick - the recursive function
 * @array: the array to be sorted
 * @start: the start of the array
 * @end: the end of the array
 * @size: the size of the array
 **/
void quick(int *array, int start, int end, size_t size)
{
	int pivot;

	/* base */
	if (start >= end)
		return;

	pivot = partition(array, start, end, size);
	quick(array, start, pivot - 1, size);
	quick(array, pivot + 1, end, size);
}

/**
 * partition - this does the sort
 * @array: the array to be sorted
 * @start: the start of the array
 * @end: the end of the array
 * @size: the size of the array
 * Return: the new povit
 **/
int partition(int *array, int start, int end, size_t size)
{
	int piv, loc, j;

	loc = start - 1;
	piv = array[end];

	for (j = start; j < end; j++)
	{
		if (array[j] <= piv)
		{
			++loc;
			if (loc != j)
			{
				swap(&array[j], &array[loc]);
				print_array(array, size);
			}
		}
	}

	if (loc + 1 != end)
	{
		swap(&array[end], &array[loc + 1]);
		print_array(array, size);
	}

	return (loc + 1);
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
