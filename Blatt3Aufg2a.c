#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc <= 1) {
		fprintf(stderr, "Usage: %s n\n", argv[0]);
		return 1;
	}

	// n, eps als Argumente lesen
	long n = atol(argv[1]);

	double sum = 0;

	for (long k = 1; k <= n; ++k) {
		sum += 1.0/(k*k);
	}

	//std::cout << sum << "\n";
	printf("%10.10lf\n", sum);

	return 0;
}
