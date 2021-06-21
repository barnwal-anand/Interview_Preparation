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

        umap[0] = 1;
        for (int num : nums) {
            prefixSum += num;
            if (umap.find(prefixSum - k) != umap.end()) {
                count += umap[prefixSum - k];
            }
            umap[prefixSum]++;
        }

	    return count;
    }
};
