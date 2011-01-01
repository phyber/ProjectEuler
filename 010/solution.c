/*
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAXPRIMES 2000000

typedef unsigned long long uint64_t;

void genprimes(char *primes) {
	uint64_t i, j;
	// Set them all to true to begin with
	for (i = 0; i < MAXPRIMES; i++) {
		primes[i] = TRUE;
	}

	// Now start marking things that aren't prime
	for (i = 2; i < MAXPRIMES; i++) {
		if (primes[i] == TRUE) {
			for (j = 2 * i; j < MAXPRIMES; j += i) {
				primes[j] = FALSE;
			}
		}
	}
}

int main(int argc, const char *argv[]) {
	unsigned long long total = 0;
	unsigned int i;
	// Not checking things is cool. JUST BELIEVE IT WILL WORK AND IT WILL.
	char *primes = malloc(sizeof(char) * MAXPRIMES);
	genprimes(primes);

	for (i = 2; i < MAXPRIMES; i++) {
		if (primes[i] == TRUE) {
			total += i;
		}
	}

	printf("Sum of primes < 2,000,000 = %llu\n", total);

	free(primes);
	return 0;
}
