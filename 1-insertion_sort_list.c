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
			temp = pointer->next;
			/*printf("%d", );*/
			if (pointer->prev->next)
				pointer->prev->next = temp;
			pointer->next = temp->next;
			temp->prev = pointer->prev;
			pointer->prev = temp;
			temp->next = pointer;
			if (temp->prev)
				pointer = temp->prev;
			else
				pointer = temp;
			print_list(*list);
		}
		else
			pointer = pointer->next;
	}

}