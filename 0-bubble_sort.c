#include "sort.h"
/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}
/**
 * bubble_sort - a function that sorts an array of integers
 * @array: the array to be sorted
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
		}
		print_array(array, size);
	}
}
