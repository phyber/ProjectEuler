#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	int i;
	unsigned int total = 0;
	for (i = 3; i < 1000; i++) {
		if ( ((i % 3) == 0 && (i % 5) == 0) || ((i % 3) == 0 || (i % 5) == 0) ) {
			total += i;
			continue;
		}
	}

	printf("Total of all multiples of 3 or 5 below 1000 == %u\n", total);
	return 0;
}
