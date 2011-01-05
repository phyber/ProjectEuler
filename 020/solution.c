#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <gmp.h>

#define TRUE 1
#define FALSE 0

void fact(mpz_t num, uint64_t fact) {
	uint64_t i;
	mpz_t tmp;
	mpz_init(tmp);
	mpz_set_ui(num, 1);

	for (i = 1; i < fact; i++) {
		mpz_set_ui(tmp, i);
		mpz_mul(num, num, tmp);
	}

	mpz_clear(tmp);
}

int main(int argc, const char *argv[]) {
	uint64_t i;
	// Large numbers
	mpz_t f, sum;
	mpz_init(f);
	mpz_init(sum);
	mpz_set_ui(sum, 0);

	//
	char *tmp = NULL;
	char tmpint[2];
	tmpint[1] = '\0';

	fact(f, 100);
	gmp_asprintf(&tmp, "%Zd", f);

	// Sum it.
	for (i = 0; i < strlen(tmp); i++) {
		memcpy(&tmpint, &tmp[i], sizeof(char) * 1);
		mpz_add_ui(sum, sum, atoi(tmpint));
	}

	// Le answer
	gmp_printf("SUM(100!) = %Zd\n", sum);

	// Clean up
	mpz_clear(f);
	mpz_clear(sum);
	free(tmp);

	return 0;
}
