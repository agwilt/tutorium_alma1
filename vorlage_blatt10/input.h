#ifndef _input_h
#define _input_h

/* Speicher allokieren
 * Parameter: Dimension der Matrix
 * Rückgabewert: zweidimensionales Array
 */
int **init_matrix(int n, int m);

/* Speicher freigeben */
void delete_matrix(int **mat, int n, int m);

/* Ausgabe der Matrux auf der Konsole */
void print_matrix(int **mat, int n, int m);

/* Einlesen der Matrix aus der Datei filename. Die Matrix und die Dimension
 * werden zurückgegeben.
 */
int **read_matrix_file(char *filename, int *n, int *m);

#endif
