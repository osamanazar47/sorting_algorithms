#include "sort.h"
/**
 * selection_sort - a function that sorts an array using selection sort
 * @array: the array to be sorted
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	int i, j, min_index;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		swap(&array[i], &array[min_index]);
		print_array(array, size);
	}
}
