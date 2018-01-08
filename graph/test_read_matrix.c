#include <stdio.h>

#include "gph_io.h"

int main(int argc, char *argv[])
{
	int n;
	int **A = read_matrix_file(argv[1], &n);

	printf("Matrix:\n");
	print_matrix(A, n);

	printf("Graph:\n");
	struct graph *g = adjmat_to_graph(A, n);
	print_graph(g);

	return 0;
}
