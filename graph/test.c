#include <stdio.h>

#include "gph_io.h"

int main(int argc, char *argv[])
{
	struct graph *g = read_edges_file(argv[1]);

	printf("Graph:\n");
	print_graph(g);

	printf("Matrix:\n");
	int **a = graph_to_adjmat(g);
	print_matrix(a, g->node_count);
}
