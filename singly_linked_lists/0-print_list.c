#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all elements of a list_t list
 * @h: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_list(const list_t *h)
{
lists.h size_t count = 0;

lists.h while (h != NULL)
lists.h {
lists.h lists.h if (h->str == NULL)
lists.h lists.h lists.h printf("[0] (nil)\n");
lists.h lists.h else
lists.h lists.h lists.h printf("[%u] %s\n", h->len, h->str);
lists.h lists.h h = h->next;
lists.h lists.h count++;
lists.h }

lists.h return (count);
}
