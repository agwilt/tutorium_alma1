#include <assert.h>
#include <err.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "gph_io.h"

void add_edge(struct graph *g, int v1, int v2)
{
	/* Prüfe Indizes auf Korrektheit */
	assert(v1 >= 1 && v2 >= 1);
	assert(v1 <= g->node_count && v2 <= g->node_count);

	/* Wir wollen keine Loops */
	assert(v1 != v2);

	struct edge *t = malloc(sizeof(struct edge));
	t->target = v2;
	t->next = g->nodes[v1-1];
	t->weight = 0.0;

	g->nodes[v1-1] = t;
}

struct graph *init(int size)
{
	struct graph *g = malloc(sizeof(struct graph));
	g->node_count = size;
	g->edge_count = 0;
	g->nodes = calloc(size, sizeof(struct edge *));
	return g;
}

void graph_free(struct graph *g)
{
	for (int i=0; i<g->node_count; ++i) {
		struct edge *next_e;
		for (struct edge *e = g->nodes[i]; e != NULL; e = next_e) {
			next_e = e->next;
			free(e);
		}
	}
	free(g->nodes);
	g->edge_count=0;
	g->node_count=0;
}

struct graph *read_edges_file(const char *filename)
{
	int node_count, edge_count;

	/* Öffne Datei */
	FILE *fp = fopen(filename, "r");
	assert(fp != NULL);

	/* Lese Anzahl Knoten */
	assert(fscanf(fp, "%d\n", &node_count) == 1);
	struct graph *g = init(node_count);
	/* Lese Anzahl Kante */
	assert(fscanf(fp, "%d\n", &edge_count) == 1);
	g->edge_count = edge_count;

	for (int i=0; i<edge_count; ++i) {
		int a, b;
		assert(fscanf(fp, "%d %d\n", &a, &b) == 2);
		add_edge(g, a, b);
	}

	fclose(fp);
	return g;
}

void write_edges_file(const char *filename, struct graph *g)
{
	/* Öffne Datei */
	FILE *fp = fopen(filename, "w");
	assert(fp != NULL);

	fprintf(fp, "%d\n", g->node_count);
	fprintf(fp, "%d\n", g->edge_count);

	for (int i=0; i<g->node_count; i++) {
		for (struct edge *e = g->nodes[i]; e!=NULL; e=e->next) {
			fprintf(fp, "%d %d\n", i+1, e->target);
		}
	}
	fclose(fp);
}

int **init_matrix(int n)
{
	assert(n > 0);

	int **mat = malloc(n * sizeof(int *));
	for (int i=0; i<n; i++)
		mat[i] = malloc(n * sizeof(int));

	return mat;
}

int **read_matrix_file(const char *filename, int *n)
{
	/* Öffne Datei und prüfe auf Erfolg */
	FILE *fp = fopen(filename, "r");
	assert(fp);

	/* Lese Knotenzahl/Dimension */
	assert(fscanf(fp, "%d\n", n) == 1);

	int **mat = init_matrix(*n);

	for (int i=0; i<*n; i++) {
		for (int j = 0; j < *n-1; j++) {
			assert(fscanf(fp, "%d,", mat[i]+j) == 1);
		}
		assert(fscanf(fp, "%d\n", mat[i]+*n-1) == 1);
	}
	fclose(fp);

	return mat;
}

void print_matrix(int **a, int n)
{
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j)
			printf("%3d ", a[i][j]);
		printf("\n");
	}
}

void print_graph(struct graph *g)
{
	printf("%d\n", g->node_count);
	printf("%d\n", g->edge_count);

	for (int i=0; i<g->node_count; i++) {
		for (struct edge *e = g->nodes[i]; e!=NULL; e=e->next) {
			printf("%d %d\n", i+1, e->target);
		}
	}
}

int **graph_to_adjmat(struct graph *g)
{
	int n = g->node_count;
	/* Initialise matrix to 0 */
	int **a = malloc(n * sizeof(int *));
	for (int i=0; i<n; ++i) a[i] = calloc(n, sizeof(int));

	/* Fill matrix */
	for (int v=1; v<=g->node_count; ++v) {
		/* Go through all outgoing edges */
		for (struct edge *e=g->nodes[v-1]; e!=NULL; e=e->next) {
			a[v-1][e->target - 1]++;
		}
	}

	return a;
}

struct graph *adjmat_to_graph(int **a, int n)
{
	struct graph *g = init(n);

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			for (int k=a[i][j]; k>0; --k) {
				add_edge(g, i+1, j+1);
			}
			g->edge_count += a[i][j];
		}
	}

	return g;
}

struct graph *tiefensuche(struct graph *g, int r)
{
	/* See if r is OK */
	if (r <= 0 || r > g->node_count) err(1, "Error: Bad root\n");
	/* Ausgabegraph t */
	struct graph *t = init(g->node_count);

	bool *visited = calloc(g->node_count, sizeof(bool));
	int *stack = malloc(g->node_count * sizeof(int));
	int *prev = malloc(g->node_count * sizeof(int));
	/* Stack pointer, zeigt immer auf den ersten Platz, wo noch nicht etwas steht */
	int *sp = stack;

	/* Start with v */
	*sp = r;
	sp++;

	/* While stack not empty */
	while(sp != stack) {
		/* pop v from stack */
		sp--;
		int v = *sp;

		/* If we haven't already visited v, do that */
		if (! visited[v-1]) {
			visited[v-1] = true;
			/* Only add edge if we aren't at v=r */
			if (v != r) {
				add_edge(t, prev[v-1], v);
				t->edge_count++;
			}

			/* have a look aroud */
			for (struct edge *e = g->nodes[v-1]; e != NULL; e=e->next) {
				int w = e->target;
				/* Push(w) */
				*sp = w;
				sp++;
				/* Remember how we got there */
				prev[w-1] = v;
			}
		}
	}

	free(visited);
	free(stack);
	free(prev);

	return t;
}
