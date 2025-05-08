#include <stdio.h>
#include <stdlib.h>

/*print out all bits of n */

void
print_binary(unsigned int n)
{
unsigned int mask = 0;

/* Creates a bit patern of 1000... */
/* regardless of the size of an unsigned int */

mask = ~mask ^ (~mask >> 1);

/* mask  -> 0 it initially sets mask to all zeros (0000..000)  */
/* ~mask -> Bitwise NOT, flips all bits to ones (1111..111) */
/* ~mask >> 1 -> Shifts those ones right by 1 position (01111.111) */
/* ~mask ^ (~mask >> 1) -> Bitwise XOR between these patterns the result will be (10000...000) */



for (; mask != 0; mask >>= 1) {
	putchar((n & mask) ? '1' : '0');
   }
}

/* About this loop */
/* it continues until the mask becomes zero (all bits are processed) */
/* it shifts mask by one position in each iteration */
/* tests if the corresponding bit in the input number is set by using the bitwise AND (&)
/* In other wors Prints 1 if the bit is  set, '0' if not */

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
/* EXAMPLE EXECUTION */
/* For Example, if we call (print_binary(42) (42 in decimal is 101010 in binary) */
/* Initial setup n = 42 (00000000000000000000000000101010 in 32 bit representation) */
/* mask start as 10000000000000000000000000000000 */
/* So after this iteration n & mask = 0  (the highest bit of 42 is not set) */
/* Print: '0' */
/* mask becomes 01000000000000000000000000000000
/* And it iterattion continues , printing each bit so final output is 00000000000000000000000000101010 (binary representation of 42 */
