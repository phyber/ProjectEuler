#include <stdio.h>
#include <string.h>

#define MAX 999
#define TRUE 1
#define FALSE 0

void strrev(char s[]) {
	int tmp, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}

int is_palindrome(unsigned int num) {
	char buf[7];
	char buf2[7];
	memset(buf, 0, sizeof(buf));
	memset(buf2, 0, sizeof(buf2));

	snprintf(buf, sizeof(buf), "%u", num);
	strncpy(buf2, buf, strlen(buf));
	strrev(buf2);

	if (strncmp(buf, buf2, sizeof(buf))) {
		return FALSE;
	}

	return TRUE;
}

int main(int argc, const char *argv[])
{
	unsigned int largest = 0;
	unsigned int i, j;
	unsigned int prod;

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
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
