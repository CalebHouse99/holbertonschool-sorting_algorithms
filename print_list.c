#include "sort.h"

/**
 * print_list - Prints a list of ints
 *
 * @list: The list to print
 */
void print_list(const listint_t *list)
{
	int a;

	a = 0;
	while (list)
	{
		if (a > 0)
			printf(", ");
		printf("%d", list->n);
		++a;
		list = list->next;
	}
	printf("\n");
}
