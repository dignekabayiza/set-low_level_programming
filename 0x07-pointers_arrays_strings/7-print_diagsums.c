#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints sum of two diagonals of a square matrix
 * @a: pointer to matrix
 * @size: size of matrix
 *
 * Return: Nothing
 */
void print_diagsums(int *a, int size)
{
int i;
long int sum1;
long int sum2;

sum1 = 0;
sum2 = 0;
for (i = 0; i < size; i++)
{
sum1 += a[i * size + i];
sum2 += a[i * size + (size - 1 - i)];
}
printf("%ld, %ld\n", sum1, sum2);
}
