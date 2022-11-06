#include "sort.h"
/**
 * 
 * 
*/
/**
 * 
 * 
*/
void partition(int *, size_t, size_t, size_t);
void swap(int *, size_t, size_t, size_t);
void partition(int *array, size_t start, size_t end, size_t size)
{
	size_t i, pindex;
	int pivot;

	if(end > start)
	{
		pindex = start;
		pivot = end;
		for(i = 0 ; i < end ; i++)
		{
			if (array[i] < pivot)
			{
				swap(array, i, pindex, size);
				pindex++;
			}
		}
		swap(array, pivot, pindex, size);
		partition(array, start, pindex - 1, size);
		partition(array, pindex + 1, end, size);
	}
}
/**
 * 
*/
void swap(int *array, size_t i, size_t pindex, size_t size)
{
	int temp;

	if(i > pindex)
	{	
		temp = array[i];
		array[i] = array[pindex];
		array[pindex] = temp;
		print_array(array, size);
	}
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
