

Shift operators are often used with bitwise logical operators to set or extract individual bits in an integer value. 

The trick is that (1 << i) contains a 1 in the i-th least significant bit and zeros everywhere else.

So x & (1<<i) is nonzero if and only if x has a 1 in the i-th place.

This can be used to print out an integer in binary format (which standard printf won’t do).

The following program gives an example of this technique.

/////

Added comments how creating initial mask works.
