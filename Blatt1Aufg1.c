#include <stdio.h>

int main()
{
	char *vorname = NULL;
	size_t len = 0;
	int tag, monat;
	int jahr;

	printf("Vorname? ");
	getline(&vorname, &len, stdin);
	printf("Geburtsjahr? ");
	scanf("%i.%i.%i", &tag, &monat, &jahr);

	printf("%s ist am %i.%i.%i geboren.\n", vorname, tag, monat, jahr);
	if (jahr % 4) {
		// kein schaltjahr
		printf("Das Geburtsjahr ist kein Schaltjahr.\n");
	} else {
		printf("Das Geburtsjahr ist ein Schaltjahr.\n");
	}

	return 0;
}
