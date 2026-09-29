#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - deletes the head node of a listint_t list
 * @head: pointer to the pointer to the head of the list
 *
 * Return: the data (n) of the deleted head node, or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *next;
	int n;

	if (head == NULL || *head == NULL)
		return (0);

	next = (*head)->next;
	n = (*head)->n;
	free(*head);
	*head = next;

	return (n);
}
