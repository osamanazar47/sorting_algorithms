#include "sort.h"
/**
 * swap_e - a function that swaps two elements
 * @a: the first element
 * @b: the second one
 */
void swap_e(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}
/**
 * selection_sort - a function that sorts an array using selection sort
 * @array: the array to be sorted
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min_index;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_index = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min_index)
				min_index = array + j;
		}
		if (min_index != array + i)
		{
			swap_e(array + i, min_index);
			print_array(array, size);
		}
	}
}
