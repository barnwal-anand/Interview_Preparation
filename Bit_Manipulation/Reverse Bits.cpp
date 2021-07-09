/*
LeetCode: 190 Reverse Bits
Reverse bits of a given 32 bits unsigned integer.

Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result= 0;

        for(int i = 0; i < 32; i++) {
            // pop from lsb of n and add it to result
            result = (result << 1) | ((n >> i) & 1);
        }

        return result;
    }
};

// More intuitive
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result= 0;

        for(int i = 0; i < 32; i++) {
            // pop from lsb of n and add it to result
            int lsb = (n >> i) & 1;
            result <<= 1;
            result = result | lsb;
        }

        return result;
    }
};
