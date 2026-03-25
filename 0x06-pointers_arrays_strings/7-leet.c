#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: pointer to string
 *
 * Return: pointer to s
 */
char *leet(char *s)
{
int i;
int j;
char plain[] = "aAeEoOtTlL";
char leet[] = "4433007711";

i = 0;
while (s[i] != '\0')
{
j = 0;
while (plain[j] != '\0')
{
if (s[i] == plain[j])
s[i] = leet[j];
j++;
}
i++;
}
return (s);
}
