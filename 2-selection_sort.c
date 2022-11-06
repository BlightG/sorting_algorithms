#include "sort.h"
/**
 * selction_sort : an implementation of the selection sort alogrithm
 *
 * @array: array of int tobe sorted
 * @size: size of int array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, temploc;
	int min, temp, flag;

	flag = 0;
	for (i = 0 ; i < size ; i++)
	{
		min = array[i];

		for (j = i ; j < size ; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				temploc = j;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			temp = array[temploc];
			array[temploc] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
		flag = 0;
	}
}
