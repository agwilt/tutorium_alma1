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

int main(int argc, char *argv[])
{
	if (argc<=1) {
		fprintf(stderr, "Usage: %s n\n", argv[0]);
		return 1;
	}

	int n = atoi(argv[1]);
	printf("%d\n", rec_fib(n));

	return 0;
}
