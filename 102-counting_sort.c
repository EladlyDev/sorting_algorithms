#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * counting sort algorithm
 *
 * @array: Pointer to array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max, i, *count, *sorted;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (i = 1; i < (int) size; i++)
		if (array[i] > max)
			max = array[i];

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	count[0] = 0;
	for (i = 0; i < (int) size; i++)
		++count[array[i]];

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	for (i = 0; i <= max; i++)
	{
		printf("%d", count[i]);
		if (i != max)
			printf(", ");
	}
	printf("\n");
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
	{
		free(count), count = NULL;
		return;
	}

	for (i = (int) size - 1; i >= 0; i--)
		sorted[count[array[i]] - 1] = array[i];
	for (i = 0; i < (int) size; i++)
		array[i] = sorted[i];
	free(sorted), sorted = NULL;
	free(count), count = NULL;
}
