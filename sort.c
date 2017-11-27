#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* mit dynamischen Arrays umgehen: */
void array_append(int **array, int *len, int *max, int x)
{
	if (*len >= *max) {
		*max += 10;
		*array = realloc(*array, (*max)*sizeof(int));
	}
	(*array)[*len] = x;
	*len = *len + 1;
}

int main()
{
	char *line = NULL;
	size_t line_len = 0;
	/* 
	 * getline holt sich automatisch mit malloc mehr RAM, falls line == NULL und len == 0.
	 * Dann setzt es line auf die neue Addresse, und len auf die Laenge
	 * stdin ist wie std::cin
	 */

	int zahl;
	int *array = NULL;
	int len = 0;
	int max = 0;

	bool sorted;

	while (getline(&line, &line_len, stdin)) {
		if (line[0] == '\0') break;	// fertig
		if (sscanf(line, "%d", &zahl)) {
			// zahl ist jetzt die neue Zahl vom User
			// sscanf gibt (in diesem Fall) 1 zurueck, falls alles geklappt hat, sonst 0
			array_append(&array, &len, &max, zahl);
		}

		free(line);
		line = NULL;
		line_len = 0;
	}

	do {
		sorted = true;
		for (int i=0; i<len-1; ++i) {
			if (array[i] > array[i+1]) {
				zahl = array[i];
				array[i] = array[i+1];
				array[i+1] = zahl;
				sorted = false;
			}
		}
	} while (sorted != true);

	for (int i = 0; i<len; ++i) {
		printf("%d\n", array[i]);
	}

	if (array != NULL) free(array);

	return 0;
}
