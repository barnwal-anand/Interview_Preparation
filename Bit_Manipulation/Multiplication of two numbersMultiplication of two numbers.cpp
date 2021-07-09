/*
The idea is based on the fact that every number can be represented in binary form.
And multiplication with a number is equivalent to multiplication with powers of 2.
Powers of 2 can be obtained using left shift operator.

Logic:
Check for every set bit in the binary representation of m
and for every set bit left shift n and add it to annswer
*/

int multiply(int num1, int num2)
{
    int res = 0;
    int index = 0;

    while (num2) {
    	if (num2 & 1) {
    		res += (num1 << index);
    	}

    	index++;
    	num2 >>= 1;
    }

    return res;
}

int main(void) {
	int num1 = 25;
	int num2 = 13;

	cout << multiply(num1, num2) << endl;

	return 0;
}
