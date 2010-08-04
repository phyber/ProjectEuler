#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int is_divisable(unsigned int num) {
	int i;
	for (i = 1; i <= 20; i++) {
		if (num % i != 0) {
			return FALSE;
		}
	}

	return TRUE;
}

int main(int argc, const char *argv[])
{
	unsigned int num = 1;
	while (1) {
		if (is_divisable(num)) {
			break;
		}
		num++;
	}

	printf("Smallest divisible by 1->20 = %u\n", num);

	return 0;
}
