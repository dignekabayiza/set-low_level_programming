#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings into newly allocated memory
 * @s1: first string (NULL is treated as an empty string)
 * @s2: second string (NULL is treated as an empty string)
 *
 * Return: pointer to the new string, or NULL if malloc fails
 */
char *str_concat(char *s1, char *s2)
{
	char *res;
	unsigned int len1, len2, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = 0;
	while (s1[len1] != '\0')
		len1++;

	len2 = 0;
	while (s2[len2] != '\0')
		len2++;

	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (res == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		res[i] = s1[i];

	for (j = 0; j <= len2; j++)
		res[len1 + j] = s2[j];

	return (res);
}
