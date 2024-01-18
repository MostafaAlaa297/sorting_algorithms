#include <stddef.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array in an ascending order
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	if (size <= 1)
		array = array;
	else
	{
		size_t i;
		int temp;
		int sorted;
		do
		{
			sorted = 1;
			for (i = 0; array && i < size - 1; i++)
			{
				if (array[i] > array[i + 1])
				{
					sorted = 0;
					temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
					print_array(array, size);
				}
			}
		} while(!sorted);
	}
}
