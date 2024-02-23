#include "sort.h"

/**
 * seletion_sort: sorts an array of integers using the selection sort algorithm
 * @array: array of integers
 * @size: size of the array
*/

void selection_sort(int *array, size_t size)
{
	int min_index, temp;
	size_t i, j;

	i = 0;
	while (i < size - 1)
	{
		/*Traverse the list to find the current min*/
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		/*Swap current min with the first unsorted element*/
		if (array[min_index] != array[i])
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
		i++;
	}

}
