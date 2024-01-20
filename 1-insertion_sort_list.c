#include <stddef.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 * in ascending order using insertion sort algorithm
 *
 * @list: The list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *current;
	
	if (list == NULL || *list == NULL)
		return;

	current = *list;

	while (current != NULL)
	{
		listint_t *next = current->next;
		if (sorted == NULL || sorted->n >= current->n)
		{
			current->prev = NULL;
			current->next = sorted;
			if (sorted != NULL)
				sorted->prev = current;
			sorted = current;
		}
		else
		{
			listint_t *temp = sorted;

			while (temp != NULL && temp->next != NULL && temp->next->n < current->n)
			{
				temp = temp->next;
			}
			current->prev = temp;
			current->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = current;
			temp->next = current;
		}
		current = next;
		print_list(sorted);
	}
	*list = sorted;
}
