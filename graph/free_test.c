#include <stdlib.h>
#include "gph_io.h"

int main(int argc, char *argv[])
{
	if (argc == 1) return 1;

	struct graph *g = read_edges_file(argv[1]);
	graph_free(g);
	free(g);
}
