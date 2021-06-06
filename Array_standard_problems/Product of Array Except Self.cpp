/*
Leetcode: 238 Product of Array Except Self
Given an integer array nums, return an array answer such that
answer[i] is equal to the product of all the elements of nums except nums[i].

You must write an algorithm that runs in O(n) time and without using the division operation.

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        vector<int> left(n);
        vector<int> right(n);

        left[0] = nums[0];
        right[n-1] = nums[n-1];

        for (int i = 1, j = n-2; i < n; i++, j--) {
            left[i] = nums[i] * left[i-1];
            right[j] = nums[j] * right[j+1];
        }

        for (int it = 0; it < n; it++) {
            int l = it > 0 ? left[it-1] : 1;
            int r = it < n-1 ? right[it+1] : 1;

            output[it] = l * r;
        }

        return output;
    }
};
