/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */

/*
 * TODO: This never actually finished running, it just so happens that the
 * last number to be spat out quickly is the answer.
 * Should really fix this.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

typedef unsigned long long uint64_t;

int is_prime(unsigned int num) {
	unsigned int i = 2;
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
	uint64_t i;
	uint64_t lpf = 0;
	uint64_t num = 600851475143;

	for (i = 1; i < num; i++) {
		if (is_prime(i)) {
			if ((num % i) == 0) {
				lpf = i;
				printf("New LPF found: %lld\n", lpf);
			}
		}
	}

	printf("Largest prime factor of %lld is %lld\n", num, lpf);

	return 0;
}
