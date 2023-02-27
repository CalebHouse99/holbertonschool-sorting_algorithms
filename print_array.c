#include "sort.h"

/**
 * print_array - Prints an array of ints
 *
 * @array: Array to print
 * @size: Num of elements
 */
void print_array(const int *array, size_t size)
{
	size_t a;

	a = 0;
	while (array && a < size)
	{
		if (a > 0)
			printf(", ");
		printf("%d", array[a]);
		++a;
	}
	printf("\n");
}
