#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc<4) {
		printf("Usage: ./makegraph filename n m");
	}

	int n = atoi(argv[2]);
	int m = atoi(argv[3]);
	int i, a, b;
	char *filename = argv[1];
	FILE *fp = fopen(filename, "w");
	if (fp == NULL) return 1;

	fprintf(fp, "%d\n", n);
	fprintf(fp, "%d\n", m);
	for (i=0; i<m; ++i) {
		a = rand()%n;
		b = rand()%n;
		if (a!=b)
			fprintf(fp, "%d %d\n", a+1, b+1);
		else
			--i;
	}
	fclose(fp);

	return 0;
}
