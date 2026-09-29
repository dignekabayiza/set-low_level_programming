#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes the node at index of a listint_t list
 * @head: pointer to the pointer to the head of the list
 * @index: index of the node to delete, starting at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *prev, *target;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		target = *head;
		*head = target->next;
		free(target);
		return (1);
	}

	prev = *head;
	for (i = 0; i < index - 1; i++)
	{
		if (prev == NULL || prev->next == NULL)
			return (-1);
		prev = prev->next;
	}

	if (prev == NULL || prev->next == NULL)
		return (-1);

	target = prev->next;
	prev->next = target->next;
	free(target);

	return (1);
}
