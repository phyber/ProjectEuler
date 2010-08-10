#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	int seq[2] = {1, 1};
	int i = 0;
	unsigned int total = 0;

	while (i < 4000000) {
		i = seq[1] + seq[0];
		seq[0] = seq[1];
		seq[1] = i;
		
		if (i % 2 == 0) {
			total += i;
		}
	}
	printf("Total: %u\n", total);

	return 0;
}
