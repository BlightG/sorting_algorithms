#include "sort.h"
/**
 * shell_sort - sorts an int array using the kunuth sequence
 * 
 * @array: array to be sorted
 * @size: size of the array
*/
void shell_sort(int *array, size_t size)
{
	size_t i, j, k, temploc, gap;
	int min, flag, temp;

	flag = gap = 0;
	if (array != NULL && size > 1)
	{
		while (size / 3 >= gap)
			gap = gap * 3 + 1;

		while (gap > 0)
		{
			for (i = 0 ; i < gap; i++)
			{
				for (j = i ; j < size ; j += gap)
				{
					min = array[j];
					for (k = j ; k < size ; k += gap)
					{
						if (min > array[k])
						{
							min = array[k];
							temploc = k;
							flag = 1;
						}
					}
					if (flag == 1)
					{
						temp = array[temploc];
						array[temploc] = array[j];
						array[j] = temp;
					}
					flag = 0;
				}
			}
			gap--;
			gap /= 3;
			print_array(array, size);
		}
	}
}
