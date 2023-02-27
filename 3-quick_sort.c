#include "sort.h"

/**
 * quick_sort - sorts quickly
 *
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	unsigned int low = 0;
	unsigned int high = (size - 1);

	if (array == NULL || size < 2)
		return;
	lom_sort(array, size, low, high);
}

/**
 * lom_sort - recurse using lomuto partitioning
 * @array: array
 * @low: left part of sub array
 * @high: right part of sub array
 * @size: size of the array
 * Return: void
 */
void lom_sort(int *array, size_t size, unsigned int low, unsigned int high)
{
	unsigned int i, j;
	int change;
	int checker;

	if (low >= high)
		return;

	change = array[high];
	j = low;

	for (i = low; i < high; i++)
	{
		if (array[i] <= change)
		{
			if (i != j)
			{
				checker = array[i];
				array[i] = array[j];
				array[j] = checker;
				print_array(array, size);
			}
			j++;
		}
	}
	if (j != high)
	{
		checker = array[high];
		array[high] = array[j];
		array[j] = checker;
		print_array(array, size);
	}
	if (j != 0)
		lom_sort(array, size, low, j - 1);
	if (j + 1 <= size - 1)
		lom_sort(array, size, j + 1, high);
}
