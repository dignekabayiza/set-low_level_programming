#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to the pointer to the head of the list
 * @idx: index where the new node should be added, starting at 0
 * @n: value to store in the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *prev;
	unsigned int i;

	if (head == NULL)
		return (NULL);

	if (idx == 0)
	{
		new = malloc(sizeof(listint_t));
		if (new == NULL)
			return (NULL);
		new->n = n;
		new->next = *head;
		*head = new;
		return (new);
	}

	prev = *head;
	for (i = 0; i < idx - 1; i++)
	{
		if (prev == NULL)
			return (NULL);
		prev = prev->next;
	}

	if (prev == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = prev->next;
	prev->next = new;

	return (new);
}
