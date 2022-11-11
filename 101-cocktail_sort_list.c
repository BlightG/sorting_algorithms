#include "sort.h"
void move_forward(listint_t **, listint_t **);
void move_backward(listint_t **, listint_t **);
int checklist(listint_t *);
/**
 * checklist - checkslist if a doubly linked list is sorted
 *
 *@list: list to be checked
 *
 *Return: 0 if list is unsorted
*/
int checklist(listint_t *list)
{
	listint_t *location;

	location = list;
	while (location->next)
	{
		if (location->next->n < location->n)
			return (0);
		location = location->next;
	}
	return (1);
}
/**
 * cocktail_sort_list - doubly sided bubble sort
 *
 * @list: boubly linked list to be sorted
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *pointer;

	if (list)
	{
		pointer = *list;
		while (checklist(*list) == 0)
		{
			move_forward(list, &pointer);
			move_backward(list, &pointer);
		}
	}
}
/**
 * move_forward - moves forwad while sorting on a list
 *
 * @list: list to be sorted
 * @newpointer: pointer to a list
*/
void move_forward(listint_t **list, listint_t **newpointer)
{
	listint_t *temp, *pointer;

	pointer = *newpointer;
	while (pointer->next)
	{
		if (pointer->next->n < pointer->n)
		{
			temp = pointer->next;
			pointer->next = temp->next;

			if (temp->next)
				temp->next->prev = pointer;
			temp->next = pointer;

			if (pointer->prev)
				pointer->prev->next = temp;
			else
			{
				*list = temp;
			}
			temp->prev = pointer->prev;
			pointer->prev = temp;
			print_list(*list);
		}
		else
			pointer = pointer->next;
	}
	*newpointer = pointer;
}
/**
 * move_backward - moves forwad while sorting on a list
 *
 * @list: list to be sorted
 * @newpointer: pointer to a list
*/
void move_backward(listint_t **list, listint_t **newpointer)
{
	listint_t *temp, *pointer;

	pointer = *newpointer;
	while (pointer->prev != NULL && pointer != NULL)
	{
		if (pointer->prev->n > pointer->n)
		{
			temp = pointer->prev;
			pointer->prev = temp->prev;

			if (temp->prev)
				temp->prev->next = pointer;
			temp->prev = pointer;

			if (pointer->next)
				pointer->next->prev = temp;
			if (!pointer->prev)
				*list = pointer;

			temp->next = pointer->next;
			pointer->next = temp;
			print_list(*list);
		}
		else
			pointer = pointer->prev;
	}
	*newpointer = pointer;
}
