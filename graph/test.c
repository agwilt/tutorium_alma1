#include <stdio.h>

#include "gph_io.h"

int main(int argc, char *argv[])
{
	struct graph *g = read_edges_file(argv[1]);

	for (int v=0; v<g->node_count; ++v) {
		for (struct edge *e=g->nodes[v]; e!=NULL; e=e->next) {
			printf("%d %d\n", v+1, e->target);
		}
	}
}
