#include <stdlib.h>
#include <stdio.h>

int my_strlen(char *s)
{
	int i = 0;
	while(s[i] != '\0')
		++i;
	return i;
}

char *string_verdoppeln(char *s)
{
	int n = my_strlen(s);
	char *copy = malloc(n * sizeof(char));
	if (copy != NULL) {
		for (int i = 0; i<=n; ++i) {
			copy[i] = s[i];
		}
	}

	return copy;
}

int main(int argc, char *argv[])
{
	if (argc <= 1) {
		printf("Bitte string angeben!\n");
		return 1;
	}

	char *s = argv[1];
	printf("Dein String hat Laenge %d\n", my_strlen(s));

	char *copy = string_verdoppeln(s);

	printf("Kopie deines Strings: %s\n", copy);

	free(copy); // bis jetzt was extra RAM fuer copy reserviert

	return 0;
}
