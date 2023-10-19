#include "lists.h"

/**
 * print_list - prints all elements of list_t list
 * @h: linked listi
 * @charles coding in c for linked lists
 * Return: number of nodes in linked list
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (z != NULL)
	{
		if (z->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", z->len, z->str);

		count++;
		z = z->next;
	}

	return (count);
}
