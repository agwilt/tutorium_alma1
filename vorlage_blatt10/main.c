#include <stdio.h>

#include "input.h"

int main(int argc, char *argv[])
{
	if (argc <= 1) {
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		return 1;
	}

	int n, m;
	int **matrix = read_matrix_file(argv[1], &n, &m);

	print_matrix(matrix, n, m);

	delete_matrix(matrix, n, m);

	return 0;
}
