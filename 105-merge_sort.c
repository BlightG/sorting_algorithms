#include "sort.h"
int * split(int *array, size_t size);
/**
 * 
*/
void merge_sort(int *array, size_t size)
{
	/*int *div;*/
	split(array , size);
	/*print_array(div, size / 2 + 1);
	free(div);*/
}
int* split(int *array, size_t size)
{
	int *left, *right;
	size_t i, j;

	if (size < 2)
		return (NULL);

	if (size % 2 == 0)
	{
		right = malloc(sizeof(int) * size / 2);
		if (!right)
			return (NULL);
		for (j = 0 , i = size / 2 ; j < size / 2 ; j++, i++)
			right[j] = array[i];
		print_array(right, (size / 2) + 1);
		left = malloc(sizeof(int) * size / 2);
		for (i = 0 ; i < (size / 2); i++)
			left[i] = array[i];
	
		if(!left)
		{
			free(right);
			return(NULL);
		}
		print_array(left, size / 2 + 1);
	}
	else
	{
		right = malloc(sizeof(int) * (size / 2) - 1);
		if (!right)
			return (NULL);
		for (j = 0 , i = (size / 2) + 1 ; j < size / 2; j++, i++)
			right[j] = array[i];
		left = malloc(sizeof(int) * size / 2 + 1);
		if(!left)
		{
			free(right);
			return(NULL);
		}
		for (i = 0 ; i <= (size / 2); i++)
			left[i] = array[i];
		print_array(right,  size / 2 + 2);
		print_array(left, size / 2 + 2);
		
	}	

	free(right);
	free(left);
	return (NULL);
}