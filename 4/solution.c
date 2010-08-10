#include <stdio.h>
#include <string.h>

#define MIN 100
#define MAX 999
#define BUFSIZE 7
#define TRUE 1
#define FALSE 0

void strrev(char *s) {
	int tmp, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}

int is_palindrome(unsigned int num) {
	char buf[BUFSIZE];
	char buf2[BUFSIZE];
	memset(buf, 0, BUFSIZE);
	memset(buf2, 0, BUFSIZE);

	snprintf(buf, BUFSIZE, "%u", num);
	strncpy(buf2, buf, strlen(buf));
	strrev(buf2);

	if (strncmp(buf, buf2, sizeof(buf)) == 0) {
		return TRUE;
	}

	return FALSE;
}

int main(int argc, const char *argv[]) {
	unsigned int largest = 0;
	unsigned int i, j;
	unsigned int prod;

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
