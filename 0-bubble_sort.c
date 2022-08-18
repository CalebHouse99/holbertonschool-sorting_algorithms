#include "sort.h"

/**
* bubble_sort - the basic sorting algorithm
*
* @array: Array
* @size: size of array
*
* Return: void
*/

void bubble_sort(int *array, size_t size)
{
	unsigned long x = 0;
	unsigned long i = 0;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (x = 0; x < size - i - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				temp = array[x];
				array[x] = array[x + 1];
				array[x + 1] = temp;
				print_array(array, size);
			}
		}
	}
}