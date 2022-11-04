#include "sort.h"
/**
 * insertion_sort_list - implementation of insertion sort using c89
 * 
 * @list: a doubly linked list composed of values
*/
void insertion_sort_list(listint_t **list)
{
	/**
	 * 1. read the first Value. 
	 * 2. compare to the secnd value.
	 * 3. if second is less move the value and chnge the pointer.
	**/
	listint_t *pointer, *temp;

	pointer = *list;
	while(pointer->next)
	{
		if(pointer->n > pointer->next->n)
		{
			printf("%d\n", pointer->n);
			temp = pointer->next;
			pointer->next = temp->next;
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
			if(temp->prev != NULL && temp->prev->n > temp->n)
				pointer = temp->prev;
			else
				pointer = temp;
			/*printf("%d\n", pointer->n);*/
			print_list(*list);
		}
		else
			pointer = pointer->next;
	}

}