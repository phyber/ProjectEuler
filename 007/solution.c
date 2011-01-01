#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

typedef unsigned long long uint64_t;

int is_prime(unsigned int num) {
	uint64_t i = 2;
	short j = 0;

	// We only need to see if numbers up to the sqrt are prime.
	unsigned int sqr = (int)sqrt(num);

	while (i <= sqr) {
		if (num % i == 0) {
			return FALSE;
		}

		// Skip even numbers if we get past % 2.
		if (i >= 5) {
			if (!j)
				i += 2;
			else
				i += 4;
			j = !j;
		}
		else {
			i++;
		}
	}

	return TRUE;
}

int main(int argc, const char *argv[]) {
	unsigned long long i = 2;
	unsigned int num_primes = 0;

	while (num_primes != 10001) {
		if (is_prime(i)) {
			num_primes++;
			//printf("Found prime: '%llu'. Total: %d\n", i, num_primes);
		}
		i++;
	}

	printf("Prime 10,001 = %llu\n", i - 1);

	return 0;
}
