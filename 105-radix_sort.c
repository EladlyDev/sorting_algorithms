#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order using the
 * Radix sort algorithm
 *
 * @array: Pointer to array to sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int i, max, place = 1;

	if (array == NULL || size <= 1)
		return;

	max = *array;
	for (i = 1; i < (int) size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	while ((max / place) > 0)
	{
		counting_sort_radix(array, size, place);
		place *= 10;
		print_array(array, size);
	}
}

/**
 * counting_sort_radix - Sorts an array of integers in ascending order using
 * the counting sort algorithm
 *
 * @array: Pointer to array to be sorted
 * @size: Size of the array
 * @place: Place value
 */
void counting_sort_radix(int *array, size_t size, int place)
{
	int i, *count, *sorted;

	count = malloc(sizeof(int) * 10);
	if (count == NULL)
		return;

	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (i = 0; i < (int) size; i++)
		++count[(array[i] / place) % 10];

	for (i = 1; i <= 9; i++)
		count[i] += count[i - 1];

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
	{
		free(count), count = NULL;
		return;
	}

	for (i = (int) size - 1; i >= 0; i--)
		sorted[--count[(array[i] / place) % 10]] = array[i];
	for (i = 0; i < (int) size; i++)
		array[i] = sorted[i];
	free(sorted), sorted = NULL;
	free(count), count = NULL;
}
