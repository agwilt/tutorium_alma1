#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	if (argc <= 1) {
		fprintf(stderr, "Usage: %s eps\n", argv[0]);
		return 1;
	}

	// n, eps als Argumente lesen
	double eps = strtod(argv[1], NULL);
	long n = 1 + 1/sqrt(eps);

	double sum = 0;

	for (long k = 1; k <= n; ++k) {
		sum += 1.0/(k*k);
	}

	printf("%16.16f\n", sqrt(6*sum));

	return 0;
}
