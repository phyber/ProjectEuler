/*
 * The sum of the squares of the first ten natural numbers is,
 *   1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is,
 *   (1 + 2 + ... + 10)^2 = 55^2 = 3025
 * Hence the difference between the sum of the squares of the first ten
 * natural numbers and the square of the sum is 3025 - 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 */

#include <stdio.h>
#include <string.h>

#define NUMBER 100

typedef unsigned long long uint64_t;

int main(int argc, const char *argv[]) {
	int i;
	uint64_t sumsq = 0;
	uint64_t sqsum = 0;
	uint64_t diff  = 0;

	for (i = 0; i <= NUMBER; i++) {
		sumsq += i * i;
		sqsum += i;
	}
	sqsum = sqsum * sqsum;
	diff = sqsum - sumsq;

	printf("Difference: %lld\n", diff);

	return 0;
}
