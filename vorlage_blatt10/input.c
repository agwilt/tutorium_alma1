#include <stdio.h>
#include <stdlib.h>

#include "input.h"

/* Speicher allokieren
 * Parameter: Dimension der Matrix
 * Rückgabewert: zweidimensionales Array
 */
int **init_matrix(int n, int m)
{
	int **mat = malloc(n * sizeof(int *));
	for (int i=0; i<n; ++i)
		mat[i] = malloc(m * sizeof(int));
	return mat;
}

/* Speicher freigeben */
void delete_matrix(int **mat, int n, int m)
{
	for (int i=0; i<n; ++i)
		free(mat[i]);
	free(mat);
}

/* Ausgabe der Matrux auf der Konsole */
void print_matrix(int **mat, int n, int m)
{
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

/* Einlesen der Matrix aus der Datei filename. Die Matrix und die Dimension
 * werden zurückgegeben.
 */
int **read_matrix_file(char *filename, int *n, int *m)
{
	/* Datei öffnen */
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		fprintf(stderr, "Error: Cannot open file: %s\n", filename);
		return NULL;
	}

	/* Lese Dimension ein. */
	if (fscanf(fp, "%d,%d\n", n, m) != 2) {
		fprintf(stderr, "Error: Invalid file format.\n");
		goto fail;
	}

	int **mat = init_matrix(*n, *m);

	/* Jetzt lesen wir die Matrix Zeile für Zeile ein. */
	for (int row=0; row<*n; row++) {
		for (int col=0; col<*m-1; col++) {
			if (fscanf(fp, "%d,", mat[row]+col) != 1) {
				fprintf(stderr, "Error: Invalid file format.\n");
				goto fail;
			}
		}
		if (fscanf(fp, "%d\n", mat[row]+(*m-1)) != 1) {
			fprintf(stderr, "Error: Invalid file format.\n");
			goto fail;
		}
	}

	fclose(fp);
	return mat;

	/* Etwas ist schief gelaufen: */
fail:
	fclose(fp);
	return NULL;
}
