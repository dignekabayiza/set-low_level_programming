#include "lists.h"

/**
 * reverse_listint - reverses a listint_t list
 * @head: pointer to the pointer to the head of the list
 *
 * Return: pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *node = *head;

	while (node)
	{
		*head = node;
		node = node->next;
		(*head)->next = prev;
		prev = *head;
	}

	return (*head);
}
