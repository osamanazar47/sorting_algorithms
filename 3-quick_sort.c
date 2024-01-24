#include "sort.h"
/**
 * swap - a function that swaps two integers
 * @a: the first integer
 * @b: the second one
 */
void swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}
/**
 * partition - Order a subset of an array of integers according to
 *             the lomuto partition scheme
 * @array: the array to be sorted
 * @size: the size of the array
 * @left: the index of the biginning og the array
 * @right: the index of the end of the array
 * Return: the final partition index
 */
int partition(int *array, size_t size, int left, int right)
{
	int *p, above, below;

	p = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *p)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *p)
	{
		swap(array + above, p);
		print_array(array, size);
	}
	return (above);
}
/**
 * sort_array - implementation of the quick sort algorithm using recursion
 * @array: the array
 * @size: the size of the array
 * @left: the starting index of the partition array
 * @right: the ending index of the partition array
 */
void sort_array(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = partition(array, size, left, right);
		sort_array(array, size, left, p - 1);
		sort_array(array, size, p + 1, right);
	}
}
/**
 * quick_sort - a function that sorts an array of integers using Quick sort
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort_array(array, size, 0, size - 1);
}
