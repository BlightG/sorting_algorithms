#include "sort.h"
void partition(int *, size_t, size_t, size_t);
void swap(int *, size_t, size_t);
/**
 * partition - partions the array into either sides of the pivot
 *
 * @array: array to be sorted
 * @start: start of the partioned array
 * @end: end of the partioned array
 * @size: size of the array
*/
void partition(int *array, size_t start, size_t end, size_t size)
{
	size_t i, pindex;
	int pivot;

	if (end > start)
	{
		pindex = start;
		pivot = array[end];
		for (i = start ; i < end ; i++)
		{
			if (array[i] < pivot)
			{
				swap(array, i, pindex);
				print_array(array, size);
				pindex++;
			}
		}
		swap(array, end, pindex);
		if (pindex >= 1)
			partition(array, start, pindex - 1, size);
		partition(array, pindex + 1, end, size);
	}
}
/**
 * swap - swaps elemets of array
 *
 * @array: array whose  elements are to be manipulated
 * @i: poistion to be moved from
 * @pindex: position to be moved to
*/
void swap(int *array, size_t i, size_t pindex)
{
	int temp;

	temp = array[i];
	array[i] = array[pindex];
	array[pindex] = temp;
}
/**
 * quick_sort - sorts  an int array using the Lumoto partions scheme
 *
 * @array:  int array to be sorted
 * @size: size of array to be sorted
*/
void quick_sort(int *array, size_t size)
{
	size_t start, end;

	start = 0;
	end = size - 1;
	partition(array, start, end, size);
}
