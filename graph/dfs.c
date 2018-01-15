#include <stdlib.h>
#include "gph_io.h"

int main(int argc, char *argv[])
{
	if (argc == 1) return 1;

	struct graph *g = read_edges_file(argv[1]);
	struct graph *t = tiefensuche(g, 1);

	print_graph(t);

	graph_free(g);
	free(g);
	graph_free(t);
	free(t);

	return 0;
}
