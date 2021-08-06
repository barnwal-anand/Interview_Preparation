/*
Leetcode: 53 Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number)
which has the largest sum and return its sum.

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_max = nums[0];
        int max_so_far = nums[0];

        for (int it = 1; it < nums.size(); it++) {
            cur_max = max(nums[it], nums[it] + cur_max);
            max_so_far = max(max_so_far, cur_max);
        }

        return max_so_far;
    }
};
