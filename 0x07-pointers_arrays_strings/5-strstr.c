#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: pointer to string to search
 * @needle: pointer to substring to find
 *
 * Return: pointer to beginning of located substring or NULL
 */
char *_strstr(char *haystack, char *needle)
{
int i;
int j;

for (i = 0; haystack[i] != '\0'; i++)
{
j = 0;
while (needle[j] != '\0' && haystack[i + j] == needle[j])
j++;
if (needle[j] == '\0')
return (haystack + i);
}
return (0);
}
