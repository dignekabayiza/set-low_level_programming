#include "main.h"

/**
 * print_rev - prints a string in reverse followed by a new line
 * @s: pointer to string
 *
 * Return: Nothing
 */
void print_rev(char *s)
{
	int len;
	int i;

	len = _strlen(s);
	for (i = len - 1; i >= 0; i--)
		_putchar(s[i]);
	_putchar('\n');
}
