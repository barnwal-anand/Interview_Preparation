/*
Leetcode: 15 - 3Sum
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Note: the solution set must not contain duplicate triplets.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int s, e;

        if (nums.size() < 3)
            return res;

        sort(nums.begin(), nums.end());

        for (int it = 0; it < nums.size() - 1; it++) {
            // to remove duplicate triplet
            if (it > 0 && nums[it] == nums[it-1])
                continue;

            s = it + 1;
            e = nums.size() - 1;

            while (s < e) {
                int sum = nums[it] + nums[s] + nums[e];
                if (sum < 0) {
                    s++;
                }
                else if (sum > 0) {
                    e--;
                }
                else {
                    res.push_back({nums[it], nums[s], nums[e]});
                    s++;
                    e--;
                    // to avoid duplicate triplet
                    while (s < nums.size() && nums[s] == nums[s-1])
                        s++;
                    while (e >= 0 && nums[e] == nums[e+1])
                        e--;
                }
            }
        }

        return res;
    }
};
