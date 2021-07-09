/*
Let n is stored using 8 bits. Left rotation of n = 11100101 by 3 makes n = 00101111
(Left shifted by 3 and first 3 bits are put back in last ).
If n is stored using 16 bits or 32 bits then left rotation of n (000…11100101) becomes 00..0011100101000.

Right rotation of n = 11100101 by 3 makes n = 10111100
(Right shifted by 3 and last 3 bits are put back in first )
*/

int leftRotate(int n, unsigned int d)
{
      // Left shifted by d and last d bits are put back in first
      return (n << d)|(n >> (INT_BITS - d));
}

/*Function to right rotate n by d bits*/
int rightRotate(int n, unsigned int d)
{
      // Right shifted by d and first d bits are put back in last
      return (n >> d)|(n << (INT_BITS - d));
}
