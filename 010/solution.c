#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int is_prime(unsigned int num) {
	unsigned int i = 2;

	// We only need to see if numbers up to the sqrt are prime.
	unsigned int sqr = (int)sqrt(num);

	while (i <= sqr) {
		if (num % i == 0) {
			return FALSE;
		}

		// Skip even numbers if we get past % 2.
		if (i > 2) {
			i += 2;
		}
		else {
			i++;
		}
	}

	return TRUE;
}

int main(int argc, const char *argv[])
{
	unsigned long long total = 0;
	unsigned int i;

	for (i = 2; i < 2000000; i++) {
		if (is_prime(i)) {
			total += i;
		}
	}

	printf("Sum of primes < 2,000,000 = %llu\n", total);

	return 0;
}
