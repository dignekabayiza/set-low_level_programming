#include "main.h"

/**
 * _strncpy - copies a string
 * @dest: pointer to destination
 * @src: pointer to source
 * @n: max bytes to copy
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
int i;

i = 0;
while (src[i] != '\0' && i < n)
{
dest[i] = src[i];
i++;
}
while (i < n)
{
dest[i] = '\0';
i++;
}
return (dest);
}
