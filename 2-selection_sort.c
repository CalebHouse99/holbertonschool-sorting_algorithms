#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the selection sort algorithm
 * @array: array of integers
 * @size: number of elements in the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t check;
	size_t sw;
	size_t small;

	for (i = 0; i < (size - 1); i++)
	{
		small = i;
		for (check = i + 1; check < size; check++)
		{
			if (array[check] < array[small])
			{
				small = check;
			}
		}
		if (small != i)
		{
			sw = array[i];
			array[i] = array[small];
			array[small] = sw;
			print_array(array, size);
		}
	}
}
