#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * compute_index - computes one of the six key indices
 * @id: which index to compute (1 to 6)
 * @username: the username
 * @len: length of the username
 *
 * Return: index into the alphabet
 */
int compute_index(int id, char *username, int len)
{
	int i, val, max;

	val = 0;
	if (id == 1)
		return ((len ^ 0x3b) & 0x3f);
	if (id == 2)
	{
		for (i = 0; i < len; i++)
			val += username[i];
		return ((val ^ 0x4f) & 0x3f);
	}
	if (id == 3)
	{
		val = 1;
		for (i = 0; i < len; i++)
			val *= username[i];
		return ((val ^ 0x55) & 0x3f);
	}
	if (id == 4)
	{
		max = username[0];
		for (i = 0; i < len; i++)
			if (username[i] > max)
				max = username[i];
		srand(max ^ 0xe);
		return (rand() & 0x3f);
	}
	if (id == 5)
	{
		for (i = 0; i < len; i++)
			val += username[i] * username[i];
		return ((val ^ 0xef) & 0x3f);
	}
	for (i = 1; i <= username[0]; i++)
		val = rand();
	return ((val ^ 0xe5) & 0x3f);
}

/**
 * main - prints a valid key for a given username
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on usage error
 */
int main(int argc, char **argv)
{
	char alphabet[65] =
		"A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char key[7];
	int len, i;

	if (argc != 2)
	{
		printf("Usage: %s username\n", argv[0]);
		return (1);
	}
	len = strlen(argv[1]);
	for (i = 1; i <= 6; i++)
		key[i - 1] = alphabet[compute_index(i, argv[1], len)];
	key[6] = '\0';
	printf("%s\n", key);
	return (0);
}
