#include "sort.h"
/**
 * bubble_sort - impelments the buble sort alogrithm
 *
 * @array: an array of integers holding numbers to be sorted
 * @size: number of integers to be sorted
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp = 0;

	for(j = 0 ; j < size ; j++)
	{
		for(i = 0; i < size - j; i++)
		{
			if (i + 1 != size - j)
			{
				if (array[i] > array[i + 1])
				{
					temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
					print_array(array, size);
				}
			}
		}
	}
}
