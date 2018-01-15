#include <stdlib.h>
#include <stdio.h>
#include "gph_io.h"

int main(int argc, char *argv[])
{
	if (argc <= 2) {
		printf("Usage: %s filename root_node\n", argv[0]);
		return 1;
	}

	int r = atoi(argv[2]);
	struct graph *g = read_edges_file(argv[1]);
	struct graph *t = tiefensuche(g, r);

	print_graph(t);

	graph_free(g);
	free(g);
	graph_free(t);
	free(t);

	return 0;
}
