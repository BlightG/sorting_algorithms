#include "sort.h"
/**
 *
 *
*/
void partition(int *, size_t, size_t, size_t);
void swap(int *, size_t, size_t);
void partition(int *array, size_t start, size_t end, size_t size)
{
	size_t i, pindex;
	int pivot;

	if(end > start)
	{
		pindex = start;
		pivot = array[end];
		for(i = start ; i < end ; i++)
		{
			if (array[i] < pivot)
			{
				swap(array, i, pindex);
				pindex++;
			}
		}
		swap(array, end, pindex);
		print_array(array, size);
		if (pindex >= 1)
			partition(array, start, pindex - 1, size);
		partition(array, pindex + 1, end, size);
	}
}
/**
 *
*/
void swap(int *array, size_t i, size_t pindex)
{
	int temp;

	temp = array[i];
	array[i] = array[pindex];
	array[pindex] = temp;
}
/**
 *
*/
void quick_sort(int *array, size_t size)
{
	size_t start, end;

	start = 0;
	end = size - 1;
	partition(array, start, end, size);
}
