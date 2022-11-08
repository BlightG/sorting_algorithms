#include "sort.h"
int * split(int *array, size_t size);
/**
 * 
*/
void merge_sort(int *array, size_t size)
{
	int *div;
	div = split(array , size);
	print_array(div, size / 2);
	free(div);
}
int* split(int *array, size_t size)
{
	int *left, *right;
	size_t i;

	if (size < 2)
		return (NULL);

	if (size % 2 == 0)
		left = malloc(sizeof(int) * size / 2);
	else
		left = malloc(sizeof(int) * (size / 2) + 1);

	if (!left)
		return (NULL);

	right = malloc(sizeof(int) * size / 2);
	
	if(!right)
	{
		free(left);
		return(NULL);
	}

	for (i = size / 2 ; i < size ; i++)
		right[i] = array[i];

	free(left);
	return (right);
}