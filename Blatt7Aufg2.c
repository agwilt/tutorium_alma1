#include <limits.h>
#include <stdio.h>

int main()
{
	unsigned int i = UINT_MAX;
	unsigned int j = UINT_MAX;

	printf("%u + %u = %u\n", i, j, i+j);

	return 0;
}
