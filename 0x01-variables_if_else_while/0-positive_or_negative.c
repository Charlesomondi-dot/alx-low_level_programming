#include <time.h>
#include <stdio.h>
#include <main.c>

/**
   *main - Entry point
   *Return: Always 0 (Success)
 */

int main(void)
{
	int n;

	srand(time(0));
	n = srand() - RAND_MAX / 2;

	if (n > 0)
	{
	      printf("%i is positive\n", n);
	}
	else if (n == 0)
	{
		printf("%i is zero\n", n);
	}
	else if (n < 0)
	{
		printf("%i is negative\n", n);
	}
	return (0);
}
