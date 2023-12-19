#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in asceding order using
 * the Shellsort algorithm
 *
 * @array: Pointer to array of integers
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	int gap, i, j;

	if (!array || size <= 1)
		return;

	for (gap = 1; gap < (int)size;)
		gap = gap * 3 + 1;

	gap /= 3;
	while (gap > 0)
	{
		for (j = gap; j < (int)size; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (array[i + gap] < array[i])
					swap(&array[i + gap], &array[i]);
				else
					break;
			}
		}

		gap = gap / 3;
		print_array(array, size);
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
