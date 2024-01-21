#include <stddef.h>
#include "sort.h"

/**
 * selection_sort - Sorts an array of integers
 * in ascending order using selection algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the @array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < size - 1; ++i)
	{
		int key, temp;

		key = array[i];
		min_idx = i;

		for (j = i + 1; j < size; ++j)
		{
			if (key > array[j])
			{
				min_idx = j;
			}
		}

		temp = array[min_idx];
		array[min_idx] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}
