#include <stdio.h>
#include <stdlib.h>

int rec_fib(int n)
{
	if (n <= 0) {
		printf("Sorry, that's not how Fibonacci numbers work.\n");
		exit(1);
	} else if (n <= 2) {
		return 1;
	} else {
		return rec_fib(n-1) + rec_fib(n-2);
	}
}

void slow_array(int n, int *zahlen)
{
	for (int i=1; i<=n; ++i) {
		zahlen[i-1] = rec_fib(i);
		printf("fibonacci(%d) = %d\n", i, zahlen[i-1]);
	}
}

void fast_array(int n, int *zahlen)
{
	/* Wir gehen davon aus, dass n >= 2. */
	zahlen[0] = zahlen[1] = 1;
	printf("fibonacci(0) = 1\n");
	printf("fibonacci(1) = 1\n");

	for (int i=2; i<n; ++i) {
		zahlen[i] = zahlen[i-2] + zahlen[i-1];
		printf("fibonacci(%d) = %d\n", i+1, zahlen[i]);
	}
}

int main(int argc, char *argv[])
{
	if (argc<=1) {
		fprintf(stderr, "Usage: %s n\n", argv[0]);
		return 1;
	}

	int n = atoi(argv[1]);
/*	printf("%d\n", rec_fib(n)); */
	int zahlen[n];

	printf("Langsame Version:\n");
	slow_array(n, zahlen);
	printf("\nSchnelle Version:\n");
	fast_array(n, zahlen);

	return 0;
}
