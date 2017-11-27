#include <stdio.h>

int main()
{
	int i, sum;
	for (i=0; i<=1000; i++) {
		if ((i%3 == 0) || (i%7 == 0))
			sum += i;
	}
	printf("%i\n", sum);
	return 0;
}
