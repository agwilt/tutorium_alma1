#ifndef _gph_io_h_
#define _gph_io_h_

#include <stdbool.h>

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
void graph_free(struct graph *g);

struct graph *read_edges_file(const char *filename, bool gerichtet);

void write_edges_file(const char *filename, struct graph *g);

int **init_matrix(int n);

int **read_matrix_file(const char *filename, int *n);

void print_matrix(int **a, int n);
void print_graph(struct graph *g);

int **graph_to_adjmat(struct graph *g);
struct graph *adjmat_to_graph(int **a, int n);

struct graph *tiefensuche(struct graph *g, int r);
int ZHK(struct graph *g);

#endif
