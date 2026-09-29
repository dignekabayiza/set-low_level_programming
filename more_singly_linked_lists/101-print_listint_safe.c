#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t list, safe against loops
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow, *fast;
	size_t nodes = 0;

	slow = head;
	fast = head;

	while (slow != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		nodes++;

		slow = slow->next;

		if (fast != NULL && fast->next != NULL)
			fast = fast->next->next;
		else
			fast = NULL;

		if (fast != NULL && slow != NULL && fast == slow)
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			return (nodes);
		}
	}

	return (nodes);
}
