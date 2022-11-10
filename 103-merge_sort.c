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
	size_t mid, i, j;
	int *temp;

	if (end <= start)
		return (NULL);
	
	mid = (end + start) / 2;

	temp = malloc(sizeof(int) * (end - start));
	if ((end - start) % 2 == 0)
	{
		split(array, start, mid);
		split(array, mid + 1, end);
		printf("start = %d, mid = %d end = %d\n", (int) start, (int) mid, (int) end);
		/*print_array(array + start , mid - start);
		print_array(array + mid, mid - start);*/
		
	}
	else
	{
		split(array, start, mid + 1);
		split(array, mid, end);
		printf("start = %d, mid = %d end = %d\n", (int) start, (int) mid, (int) end);
		/*print_array(array + start, mid - start + 1);
		print_array(array + mid + 1, mid - start);*/
	}
	
	for (i = 0 , j = start ; i < (end - start) ; j++, i++)
	{
		temp[i] = array[j];
	}

	print_array(temp, end - start);
	free(temp);
	return (NULL);
}
