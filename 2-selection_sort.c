#include "sort.h"
/**
 * 
 * 
*/
void selection_sort(int *array, size_t size)
{
        size_t i, j;
        int min, temp;

        for(i = 0 ; i < size ; i++)
        {
                min = array[i];
                for(j = i ; j < size ; j++)
                {
                        if(min > array[j])
                        {
                                temp = min;
                                min = array[j];
                                array[j] = temp;
                        }
                }
                array[i] = min;
                print_array(array, size);
        }
}