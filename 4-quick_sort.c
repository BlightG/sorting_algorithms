#include "sort.h"
/**
 * 
*/
void swap(int *, size_t, int);
void swap(int *array, size_t i, int pindex)
{
	int temp;

	if((int) i > pindex)
	{	
		temp = array[i];
		array[i] = array[pindex];
		array[pindex] = temp;
	}
}
/**
 * 
 * 
 * 
*/
void quick_sort(int *array, size_t size)
{
	size_t i;
	int pindex, pivot;

	pindex = 0;
	pivot = array[size - 1];
	for(i = 0 ; i < size - 1 ; i++)
	{
		if (array[i] < pivot)
		{
			swap(array, i, pindex);
			pindex++;
		}
	}
	swap(array, size - 1, pindex);
	/*partion(array, start, end);
	partion(array , start, end);*/
	print_array(array, size);
}
/**
 * choose the last number of the array as the pivot
 * and compare it to the other number unitl you find 
 * the pivot correct spot of the pivot 
 * 
 * make sure to move the smaller numbers to the left
 * and the larger unmbers to the right 
 * 
 * repeat the above  steps until Fully sorted
*/