/*
Leetcode: 560. Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
	  int prefixSum = 0;
        unordered_map<int, int> umap;

        for (int num : nums) {
            prefixSum += num;
            if (prefixSum == k) {
                count++;
            }
            if (umap.find(prefixSum - k) != umap.end()) {
                count += umap[prefixSum - k];
            }
            umap[prefixSum]++;
        }

	    return count;
    }
};

/*
One more variation
Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.

N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements from 2nd position to 4th position is 12.
*/

vector<int> subarraySum(int arr[], int n, int s)
{
    int prefix_sum = 0;
    int start_index = 0;
        
    for (int it = 0; it < n; it++) {
        prefix_sum += arr[it];
            
        while (prefix_sum >= s) {
            if (prefix_sum == s) {
                return {start_index + 1, it + 1};
            }
            prefix_sum -= arr[start_index];
            start_index++;
        }
    }
        
    return {-1};
}
