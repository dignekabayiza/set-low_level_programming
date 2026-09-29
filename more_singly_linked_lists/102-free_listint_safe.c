#include "lists.h"
#include <stdlib.h>

/**
 * find_loop - finds a node inside a loop, using Floyd's algorithm
 * @head: pointer to the head of the list
 *
 * Return: pointer to a node in the loop, or NULL if there is none
 */
static listint_t *find_loop(listint_t *head)
{
	listint_t *tortoise, *hare;

	tortoise = head;
	hare = head;

	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (tortoise == hare)
			return (tortoise);
	}

	return (NULL);
}

/**
 * break_loop - finds the entry point of a loop and cuts it
 * @head: pointer to the head of the list
 * @meet: a node known to be inside the loop
 *
 * Return: Nothing.
 */
static void break_loop(listint_t *head, listint_t *meet)
{
	listint_t *tortoise, *tmp;

	tortoise = head;
	while (tortoise != meet)
	{
		tortoise = tortoise->next;
		meet = meet->next;
	}

	tmp = meet;
	while (tmp->next != meet)
		tmp = tmp->next;
	tmp->next = NULL;
}

/**
 * free_listint_safe - frees a listint_t list, safe against loops
 * @h: pointer to the pointer to the head of the list
 *
 * Return: the number of nodes that were freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *meet, *tmp;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	meet = find_loop(*h);
	if (meet != NULL)
		break_loop(*h, meet);

	while (*h)
	{
		tmp = (*h)->next;
		free(*h);
		*h = tmp;
		count++;
	}

	*h = NULL;

	return (count);
}
