#include "sort.h"

/**
 * swap - swaps two pointers.
 * @xp: first pointer.
 * @yp:  second pointer.
 *
 * Return: void
 */

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
* selection_sort - selection sort algrithm
*
*@array: Array
*@size: size of array
*
*Return: void
*/

void selection_sort(int *array, size_t size)
{
	size_t i, x, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (x = i + 1; x < size; x++)
		{
			if (array[x] < array[min])
				min = x;
		}
			if (min != i)
			{
				swap(&array[min], &array[i]);
				print_array(array, size);
			}
	}
}
