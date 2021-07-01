/*
Leetcode: 46 Permutations
Given an array nums of distinct integers, return all the possible permutations.
You can return the answer in any order.

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;

        permuteUtil(nums, 0, res);

        return res;
    }

    void permuteUtil(vector<int> &nums, int s, vector<vector<int>> &res) {
        if (s == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int it = s; it < nums.size(); it++) {
            swap(nums[s], nums[it]);
            permuteUtil(nums, s+1, res);
            swap(nums[s], nums[it]);
        }
    }
};
