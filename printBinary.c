#include <stdio.h>
#include <stdlib.h>

/*print out all bits of n */

void
print_binary(unsigned int n)
{
unsigned int mask = 0;

/* this grotesque hack create a bit patern of 1000... */
/* regardless of the size of an unsigned int */

mask = ~mask ^ (~mask >> 1);

for (; mask != 0; mask >>= 1) {
	putchar((n & mask) ? '1' : '0');
   }
}

int
main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s n\n", argv[0]);
		return 1;
	}

	print_binary(atoi(argv[1]));
	putchar('\n');

	return 0;
}


/* You can set the i-th bit of x to 1 by doing  x | (1 << i) or to 0 by doing x & ~(1 << i) */
/* Check changes to see how to implement both */
