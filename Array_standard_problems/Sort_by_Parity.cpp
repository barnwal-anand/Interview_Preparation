// Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.
i/p: [4,2,5,7]
o/p: [4,5,2,7]

Approach:
If we only consider to place even at even place, then odd will be automatically be place at odd places.

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int evenIndex = 0;
        int oddIndex = 1;

        while (evenIndex < A.size())
        {
            if (A[evenIndex] % 2 == 0)
            {
                evenIndex += 2;
            }
            else
            {
                while (A[oddIndex] % 2 != 0)
                {
                    oddIndex += 2;
                }

                int temp = A[evenIndex];
                A[evenIndex] = A[oddIndex];
                A[oddIndex] = temp;
            }
        }

        return A;
    }
};
