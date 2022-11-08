#include "sort.h"
int* split(int *array, size_t start, size_t end);
int* merge(int *array, int* left, int* right, size_t lsize, size_t rsize);
/**
 *
*/
void merge_sort(int *array, size_t size)
{
	/*int *div;*/
	split(array , 0, size);
	/*print_array(div, size / 2 + 1);
	free(div);*/
}
int* split(int *array, size_t start, size_t end)
{
	int *left, *right;
	size_t i, j, mid;

	if (end - start < 1)
		return (NULL);

	mid = (end - start) / 2;
/*	if (size % 2 == 0)
		lsize = size / 2;
	else
		lsize = size / 2 + 1;*/

	left = malloc(sizeof(int) * (mid - start));
	if(!left)
		return(NULL);
	right = malloc(sizeof(int) * ((mid + 1) - end ));
	if (!right)
	{
		free(left);
		return(NULL);
	}

	for (i = start ; i < mid ; i++)
		left[i] = array[i];

	for (j = 0 , i = mid + 1 ; j < end; j++, i++)
		right[j] = array[i];

	split(array, start, mid);
	split(right, mid + 1, end);

	merge(array, left, right, mid - start, (mid + 1) - end);

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
