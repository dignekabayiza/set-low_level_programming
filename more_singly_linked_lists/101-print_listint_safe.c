#include "lists.h"

/**
 * print_listint_safe - prints a listint_t list, safe against loops
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tmp, *start;
	size_t count, i;

	count = 0;
	tmp = head;

	while (tmp)
	{
		printf("[%p] %d\n", (void *)tmp, tmp->n);
		count++;
		tmp = tmp->next;

		start = head;
		i = 0;
		while (i < count)
		{
			if (start != tmp)
			{
				start = start->next;
				i++;
			}
			else
			{
				printf("-> [%p] %d\n", (void *)start, start->n);
				return (count);
			}
		}
	}

	return (count);
}
