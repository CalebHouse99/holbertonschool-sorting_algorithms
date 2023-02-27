#include "sort.h"

/**
 * swap - swaps 2 elements in array
 *
 * @a: element one
 * @b: element two
*/

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * heapify - creates a sorted heap array
 *
 * @array: array
 * @sub_array_size: size of array
 * @size: size of full array
 * @i: heap root
*/
void heapify(int *array, int sub_array_size, size_t size, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < sub_array_size && array[left] > array[largest])
		largest = left;

	if (right < sub_array_size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, sub_array_size, size, largest);
	}
}

/**
 * heap_sort - uses heap sort
 *
 * @array: array to sort
 * @size: size of array
*/
void heap_sort(int *array, size_t size)
{
	int i;
	int size_int = (int)size;

	for (i = size_int / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, size, i);
	}

	for (i = size_int - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i > 0)
			print_array(array, size);
		heapify(array, i, size, 0);
	}
}
