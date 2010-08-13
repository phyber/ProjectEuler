#include <stdio.h>
#include <string.h>

#define MIN 100
#define MAX 999
#define BUFSIZE 7
#define TRUE 1
#define FALSE 0

int is_palindrome(unsigned int num) {
	int i, j;
	char buf[BUFSIZE];
	memset(buf, 0, BUFSIZE);
	snprintf(buf, BUFSIZE, "%u", num);

	for (i = 0, j = strlen(buf) - 1; i < j; i++, j--) {
		// Compare first half of the string to the 2nd half.
		// If they don't match, bail out.
		if (buf[i] != buf[j]) {
			return FALSE;
		}
	}

	// If we're here, everything matched and we have a palindrome!
	return TRUE;
}

int main(int argc, const char *argv[]) {
	unsigned int largest = 0;
	unsigned int i, j;
	unsigned int prod;

	// There's probably a fancy way to cancel out a bunch of these numbers
	// and make the loop shorter.
	for (i = MIN; i < MAX; i++) {
		for (j = MIN; j < MAX; j++) {
			prod = i * j;
			if (is_palindrome(prod)) {
				if (prod > largest) {
					largest = prod;
				}
			}
		}
	}

	printf("Largest Palindrome: %u\n", largest);

	return 0;
}
