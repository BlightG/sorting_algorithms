#include "sort.h"
void splitleft(int *, size_t);
void splitright(int *, size_t , size_t);
/**
 * 
*/
void merge_sort(int *array, size_t size)
{
	if (size > 0)
	{
		if (size % 2 == 0)
		{
			splitleft(array, size/2);
			splitright(array, size, size/2);
		}
		else
		{
			splitleft(array, (size / 2) + 1);
			splitright(array, size, size/2);
		}
	}
}
void splitleft(int *array, size_t pointer)
{
	if (pointer > 1)
	{
		if(pointer % 2 == 0)
			splitleft(array, pointer/2);
		else
			splitleft(array, (pointer / 2) + 1);
		printf("pointer = %d\n", (int) pointer);
		print_array(array, pointer);
	}
	else if(pointer == 1)
	{
		printf("pointer = %d\n", (int) pointer);
		print_array(array, pointer);
	}
}
void splitright(int *array, size_t size, size_t pointer)
{
	if (pointer > 1)
	{
		if(pointer % 2 == 0)
			splitright(array, size, pointer/2);
		else
			splitright(array, size, (pointer / 2));
		printf("pointer = %d\n", (int) pointer);
		print_array(array + (size - pointer), pointer);
	}
	else if(pointer == 1)
	{
		printf("pointer = %d\n", (int) pointer);
		print_array(array + (size - pointer), pointer);
	}
}
