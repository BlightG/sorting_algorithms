#include "sort.h"
/**
 * 
 * 
*/
void selection_sort(int *array, size_t size)
{
        size_t i, j, temploc;
        int min, temp;

        for(i = 0 ; i < size - 1 ; i++)
        {
                min = array[i];
                for(j = i ; j < size ; j++)
                {
                        if(min > array[j])
                        {
                                min = array[j];
                                temploc = j;
                        }
                }
                temp = array[temploc];
                array[temploc] = array[i];
                array[i] = temp;

                print_array(array, size);
        }
}
