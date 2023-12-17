#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in asceding order using
 * the Bubble sort algorithm
 *
 * @array: Pointer to array of integers
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int i, j;

	for (i = 0; i < (int) size; i++)
	{
		for (j = 0; j < (int) size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
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
