#include "sort.h"

/**
 * merge_sort - merge sorts
 * @array: pointer to array
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp_arr = malloc(sizeof(array[0]) * size);

	copy_array(array, 0, size, tmp_arr);
	recur_split(tmp_arr, 0, size, array);
	free(tmp_arr);
}

/**
 * print_the_array - prints array
 * @array: pointer to array
 * @start: start point of array
 * @end: end point of array
 */
void print_the_array(int *array, int start, int end)
{
	int i;

	for (i = start; i < end; i++)
	{
		printf("%d", array[i]);
		if (i < end - 1)
			printf(", ");
		else
			printf("\n");
	}
}

/**
 * copy_array - copies array into temp array
 * @array: pointer to array to copy
 * @start: start point of array
 * @tmp_arr: pointer to temporary array
 * @end: end point of array
 */
void copy_array(int *array, int start, int end, int *tmp_arr)
{
	int i;

	for (i = start; i < end; i++)
		tmp_arr[i] = array[i];
}

/**
 * recur_split - recursively splits array into subarrays
 * @array: pointer to array to sort
 * @tmp_arr: pointer to temporary array
 * @start: start point of array
 * @end: end point of array
 */
void recur_split(int *tmp_arr, int start, int end, int *array)
{
	int mid = (start + end) / 2;

	if (end - start <= 1)
		return;
	recur_split(array, start, mid, tmp_arr);
	recur_split(array, mid, end, tmp_arr);
	merge_it(tmp_arr, start, mid, end, array);
}

/**
 * merge_it - merges two subarrays
 * @array: pointer to array to sort
 * @tmp_arr: pointer to temporary array
 * @start: start point of array
 * @mid: middle point of array
 * @end: end point of array
 */
void merge_it(int *array, int start, int mid, int end, int *tmp_arr)
{
	int i = start, j = mid, k = start;

	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || array[i] <= array[j]))
		{
			tmp_arr[k] = array[i];
			i++;
		}
		else
		{
			tmp_arr[k] = array[j];
			j++;
		}
	}
	printf("Merging...\n[left]: ");
	print_the_array(array, start, mid);
	printf("[right]: ");
	print_the_array(array, mid, end);
	printf("[Done]: ");
	print_the_array(tmp_arr, start, end);
}
