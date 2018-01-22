#include <stdlib.h>
#include <stdio.h>
#include "gph_io.h"

int main(int argc, char *argv[])
{
	if (argc <= 1) {
		printf("Usage: %s filename\n", argv[0]);
		return 1;
	}

	struct graph *g = read_edges_file(argv[1], false);
	printf("Anzahl ZHK: %d\n", ZHK(g));

	graph_free(g);
	free(g);

	return 0;
}
