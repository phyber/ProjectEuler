/*
 * If we list all the natural numbers below 10 that are multiples of 3 or 5,
 * we get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	int i;
	unsigned int total = 0;
	for (i = 3; i < 1000; i++) {
		if ( ((i % 3) == 0 && (i % 5) == 0) || ((i % 3) == 0 || (i % 5) == 0) ) {
			total += i;
		}
	}

	printf("Total of all multiples of 3 or 5 below 1000 == %u\n", total);
	return 0;
}
