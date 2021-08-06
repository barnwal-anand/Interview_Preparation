/*
Leetcode - 1588: Sum of All Odd Length Subarrays
Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
*/

/*
Approach 1:
-----------
Just see number of times every position occurs in all the odd length subarray.
Multiply the contribution of position with element at that position.

How to calculate contribution?
Every element will contribute size of array to its right (n-i) * size of array to its left(i+1)
Since here we only consider odd length divide it by two (ceil divison)


Example
Given array: arr = [1, 2, 3, 4, 5] (n = 5) and formula (i + 1) * (n - i)
i = 0, contribution = 1 * 5 = 5
i = 1, contribution = 2 * 4 = 8
i = 2, contribution = 3 * 3 = 9
i = 3, contribution = 4 * 2 = 8
i = 4, contribution = 5 * 1 = 5
*/
int sumOddLengthSubarrays(vector<int>& arr) {
      int res = 0;
      int size = arr.size();
      int multiple;

      for (int it = 0; it < size; it++) {
            multiple = ((it+1)*(size-it) + 1)/2;
            res += arr[it]*multiple;
      }

      return res;
 }

 /*
 Brute force:
 ------------
 */
class Solution {
public:
    int findSum(vector<int> arr, int i, int j) {
        int sum = 0;

        for (int l = i; l <= j; l++) {
            sum += arr[l];
        }

        return sum;
    }

    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;

        for (int i = 0; i < arr.size(); i++) {
            res += arr[i];
            for (int j = i + 1; j < arr.size(); j++) {
                if ((j - i + 1) % 2 != 0) {
                    res += findSum(arr, i, j);
                }
            }
        }

        return res;
    }
};
