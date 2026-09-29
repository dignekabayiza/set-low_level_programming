#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - frees a listint_t list, safe against loops
 * @h: pointer to the pointer to the head of the list
 *
 * Return: the number of nodes that were freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tortoise, *hare, *tmp;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	tortoise = *h;
	hare = *h;

	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			tortoise = *h;
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}

			tmp = hare;
			while (tmp->next != hare)
				tmp = tmp->next;
			tmp->next = NULL;
			break;
		}
	}

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
