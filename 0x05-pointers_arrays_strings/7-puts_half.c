#include "main.h"

/**
 * puts_half - prints half of a string
 * @str: pointer to string
 *
 * Return: Nothing
 */
void puts_half(char *str)
{
int len;
int i;

len = 0;
while (str[len] != '\0')
len++;
if (len % 2 == 0)
i = len / 2;
else
i = (len - 1) / 2 + 1;
while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}
_putchar('\n');
}
