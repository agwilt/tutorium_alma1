#ifndef _gph_io_h_
#define _gph_io_h_

struct graph {
	/* Array von listen von Kanten */
	struct edge **nodes;
	int node_count;
	int edge_count;
};

struct edge {
	int target;
	double weight;
	/* Nächste Kante in Adjazenzliste */
	struct edge *next;
};

void add_edge(struct graph *g, int v1, int v2);

struct graph *init(int size);

struct graph *read_edges_file(const char *filename);

void write_edges_file(const char *filename, struct graph *g);

int **init_matrix(int n);

int **read_matrix_file(const char *filename, int *n);

void print_matrix(int **a, int n);
void print_graph(struct graph *g);

#endif
