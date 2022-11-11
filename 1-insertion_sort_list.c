#include "sort.h"
/**
 * insertion_sort_list - implementation of insertion sort using c89
 *
 * @list: a doubly linked list composed of values
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *pointer, *temp;

	pointer = *list;
	if (list)
	{
		while (pointer->next)
		{
			if (pointer->n > pointer->next->n)
			{
				temp = pointer->next;
				pointer->next = temp->next;

				if (temp->next)
					temp->next->prev = pointer;
				temp->next = pointer;

				if (pointer->prev)
				{
					pointer->prev->next = temp;
					temp->prev = pointer->prev;
					pointer->prev = temp;
				}
				else
				{
					temp->prev = NULL;
					pointer->prev = temp;
					*list = temp;
				}

				if (temp->prev != NULL && temp->prev->n > temp->n)
					pointer = temp->prev;
				else
					pointer = temp;
				print_list(*list);
			}
			else
				pointer = pointer->next;
		}
	}
}
