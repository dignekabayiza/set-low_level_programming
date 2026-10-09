#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at a given index
 * @head: double pointer to the head of the list
 * @index: index of the node to delete, starting at 0
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	node = *head;

	for (i = 0; i < index; i++)
	{
		node = node->next;
		if (node == NULL)
			return (-1);
	}

	if (node->prev != NULL)
		node->prev->next = node->next;
	else
		*head = node->next;

	if (node->next != NULL)
		node->next->prev = node->prev;

	free(node);
	return (1);
}
