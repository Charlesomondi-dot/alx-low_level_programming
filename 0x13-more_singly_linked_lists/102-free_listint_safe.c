#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely, avoiding loops
 * @h: Pointer to a pointer to the head of the list
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h) 
{
	listint_t *current, *temp;
	size_t count = 0;

	current = *h; /* Set current pointer to the head of the list */

	while (current != NULL) 
	{
		count++; /* Increment the count for each node */

		/* Check if the next node points back to a previously visited node (loop) */
		if (current > current->next) 
		{
			*h = NULL; /* Set head to NULL to avoid accidental access */

			/* Free the remaining nodes and break the loop */
			while (current != NULL) 
			{
				temp = current;
				current = current->next;
				free(temp);
			}

			break; /* Exit the loop */
		}

		temp = current; /* Store the current node */
		current = current->next; /* Move to the next node */
		free(temp); /* Free the stored node */
	}

	return count; /* Return the size of the list that was freed */
}

