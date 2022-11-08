#include "sort.h"
int * split(int *array, size_t size);
int* merge(int *array, int* left, int* right, size_t lsize, size_t rsize);
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
	size_t i, j, rsize, lsize;

	if (size < 2)
		return (NULL);

	rsize = size / 2;
	if (size % 2 == 0)
		lsize = size / 2;
	else
		lsize = size / 2 + 1;

	left = malloc(sizeof(int) * lsize);
	if(!left)
		return(NULL);
	right = malloc(sizeof(int) * rsize);
	if (!right)
	{
		free(left);
		return(NULL);
	}

	for (i = 0 ; i < lsize; i++)
		left[i] = array[i];

	for (j = 0 , i = lsize ; j < rsize; j++, i++)
		right[j] = array[i];

	split(left, lsize);
	split(right, rsize);

	merge(array, left, right, lsize, rsize);

	free(right);
	free(left);
	return (NULL);
}

int* merge(int *array, int* left, int* right, size_t lsize, size_t rsize)
{
	size_t i, j, k;

	k = i = j = 0;
	if (array == NULL || left == NULL || right == NULL)
		return (NULL);
	if (rsize < 1 || lsize < 1)
		return (NULL);

	while(i < lsize && j < rsize)
	{
		if(left[i] <= right[j])
		{
			array[k] = left[i];
			k++;
			i++;
		}
		else
		{
			array[k] = right[j];
			k++;
			j++;
		}
	}
	while(i < lsize)
	{
		array[k] = left[i];
		k++;
		i++;
	}
	while(j < rsize)
	{
		array[k] = right[j];
		k++;
		j++;
	}

	printf("Merging...\n[left]: ");
	print_array(left, lsize);
	printf("[right]: ");
	print_array(right, rsize);
	printf("[Done]: ");
	print_array(array, lsize + rsize);
	return(array);
}
