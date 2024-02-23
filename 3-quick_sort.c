#include "sort.h"

/**
 * partition - Lomuto partition scheme
 * @array: array of integers
 * @l: starting index of the partition to be sorted
 * @h: ending index of the partition to be sorted
 * @size: array size
 *
 * Return: index of the pivot element after partitioning
 */
int partition(int *array, int l, int h, size_t size)
{
	int pivot, temp, i, j;

	pivot = array[h];
	i = l - 1;

	for (j = l; j <= h - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[h];
	array[h] = temp;
	print_array(array, size);

	return (i + 1);
}

/**
 * quicksort - recursive function to implement quick sort
 * @array: array of integers
 * @l: starting index of the partition to be sorted
 * @h: ending index of the partition to be sorted
 * @size: size of the array
 */
void quicksort(int *array, int l, int h, size_t size)
{
	if (l < h)
	{
		int pi = partition(array, l, h, size);

		quicksort(array, l, pi - 1, size);
		quicksort(array, pi + 1, h, size);
	}
}

/**
 * quick_sort - sorts an array of integers using Quick sort
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
