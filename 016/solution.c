/*
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 2^1000?
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <gmp.h>

int main(int argc, const char *argv[]) {
	uint64_t i;
	// Declare and initialize the sum and the base.
	mpz_t sum, base, bignum;
	mpz_init(sum);
	mpz_init(base);
	mpz_init(bignum);

	// Somewhere to store  the char representation of our bignum
	// and temp space for each number we will sum.
	char *sumnum = NULL;
	char tmpint[2];
	tmpint[1] = '\0';

	// Set the exponent to 1000
	uint64_t exp = 1000;

	// Set the base to 2
	mpz_set_ui(base, 2);

	// Perform the calculation: bignum = base^exp
	mpz_pow_ui(bignum, base, exp);

	// Now turn that into a char array so we can sum each number.
	gmp_asprintf(&sumnum, "%Zd", bignum);

	// Now sum the thing.
	for (i = 0; i < strlen(sumnum); i++) {
		memcpy(&tmpint, &sumnum[i], sizeof(char) * 1);
		mpz_add_ui(sum, sum, atoi(tmpint));
	}

	gmp_printf("Sum Total: %Zd\n", sum);

	// Clear up
	mpz_clear(sum);
	mpz_clear(base);
	mpz_clear(bignum);
	free(sumnum);

	return 0;
}
