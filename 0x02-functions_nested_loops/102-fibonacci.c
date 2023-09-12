#include <stdio.h>

/**
 * main - print first 50 Fibonacci numbers
 * Return: 0
 */

int main(void)
{
	int counter;
	int countto = 50;
	long a = 1;
	long b = 2;

	printf("%li", a);

	for (counter = 1; counter <= (countto / 2); counter++)
	{
		printf(", %li", b);
		a + = b;
		b + = a;
	}

	printf("\n");

	return (0);

}
