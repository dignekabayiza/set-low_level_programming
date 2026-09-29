#include "lists.h"

/**
 * find_listint_loop - finds the loop in a listint_t list
 * @head: pointer to the head of the list
 *
 * Return: address of the node where the loop starts, or NULL if there is none
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise, *hare;

	tortoise = head;
	hare = head;

	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}
			return (tortoise);
		}
	}

	return (NULL);
}
