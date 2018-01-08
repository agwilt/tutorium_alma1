#include <stdio.h>

#include "gph_io.h"

int main(int argc, char *argv[])
{
	struct graph *g = read_edges_file(argv[1]);

	print_graph(g);
}
