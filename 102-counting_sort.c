#include "sort.h"
/**
 * counting_sort - sorts an array of int using the counting alorithm
 *
 * @array: unosrted int array
 * @size: size of @array
*/
void counting_sort(int *array, size_t size)
{
	size_t i;
	int max, temp;
	int *counting;

	max = array[0];
	for (i = 0 ; i < size ; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	counting = malloc(sizeof(int) * (max + 1));
	if (!counting)
		exit(0);

	memset(counting, 0, max + 1);

	for (i = 0 ; i < size ; i++)
	{
		temp = array[i];
		counting[temp]++;
	}

	temp = 0;
	for (i = 0 ; (int) i <= max ; i++)
	{

		if (counting[i] != 0)
		{
			array[temp] = i;
			temp++;
		}
		counting[i] = temp;
	}
	print_array(counting, max + 1);
	free(counting);
}
