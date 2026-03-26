#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: pointer to string
 * @accept: pointer to accepted characters
 *
 * Return: number of bytes in initial segment of s from accept
 */
unsigned int _strspn(char *s, char *accept)
{
unsigned int i;
int j;
int found;

i = 0;
while (s[i] != '\0')
{
found = 0;
for (j = 0; accept[j] != '\0'; j++)
{
if (s[i] == accept[j])
found = 1;
}
if (!found)
return (i);
i++;
}
return (i);
}
