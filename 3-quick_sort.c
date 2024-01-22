#include <stddef.h>
#include "sort.h"

/**
 * swap - Swaps two elements
 *
 * @a: The first element
 * @b: The second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Divide the array into parts for sorting
 *
 * @array: The array to be sorted
 * @low: The lower element
 * @high: The higher element
 * @size: The size of the @array
 *
 * Return: The index of the new pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_recursive - Sorts an array of integers
 * in ascending order using the quick sort algorithm
 *
 * @array: The array to be sorted
 * @low: Lower element of the partition
 * @high: Higher element of the partition
 * @size: The size of the @array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array og integers
 * in ascending order using quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the @array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}
