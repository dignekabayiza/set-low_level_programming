#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * f1 - computes index 1
 * @len: length of username
 *
 * Return: index into the alphabet
 */
int f1(int len)
{
	return ((len ^ 0x3b) & 0x3f);
}

/**
 * f2 - computes index 2
 * @username: the username
 * @len: length of username
 *
 * Return: index into the alphabet
 */
int f2(char *username, int len)
{
	int sum = 0;
	int i;

	for (i = 0; i < len; i++)
		sum += username[i];
	return ((sum ^ 0x4f) & 0x3f);
}

/**
 * f3 - computes index 3
 * @username: the username
 * @len: length of username
 *
 * Return: index into the alphabet
 */
int f3(char *username, int len)
{
	int prod = 1;
	int i;

	for (i = 0; i < len; i++)
		prod *= username[i];
	return ((prod ^ 0x55) & 0x3f);
}

/**
 * f4 - computes index 4
 * @username: the username
 * @len: length of username
 *
 * Return: index into the alphabet
 */
int f4(char *username, int len)
{
	int max = username[0];
	int i;

	for (i = 0; i < len; i++)
		if (username[i] > max)
			max = username[i];
	srand(max ^ 0xe);
	return (rand() & 0x3f);
}

/**
 * f5 - computes index 5
 * @username: the username
 * @len: length of username
 *
 * Return: index into the alphabet
 */
int f5(char *username, int len)
{
	int sum = 0;
	int i;

	for (i = 0; i < len; i++)
		sum += username[i] * username[i];
	return ((sum ^ 0xef) & 0x3f);
}

/**
 * f6 - computes index 6
 * @c: first character of username
 *
 * Return: index into the alphabet
 */
int f6(int c)
{
	int r = 0;
	int i;

	for (i = 1; i <= c; i++)
		r = rand();
	return ((r ^ 0xe5) & 0x3f);
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
	int len;

	if (argc != 2)
	{
		printf("Usage: %s username\n", argv[0]);
		return (1);
	}
	len = strlen(argv[1]);
	key[0] = alphabet[f1(len)];
	key[1] = alphabet[f2(argv[1], len)];
	key[2] = alphabet[f3(argv[1], len)];
	key[3] = alphabet[f4(argv[1], len)];
	key[4] = alphabet[f5(argv[1], len)];
	key[5] = alphabet[f6(argv[1][0])];
	key[6] = '\0';
	printf("%s\n", key);
	return (0);
}
