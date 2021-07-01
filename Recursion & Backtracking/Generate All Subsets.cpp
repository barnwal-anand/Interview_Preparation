/*
Leetcode: 78 Subsets
Given an integer array nums of unique elements, return all possible subsets (the power set).

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;

        generateAllSubset(nums, 0, res, temp);
        return res;
    }

    void generateAllSubset(vector<int>& arr, int it, vector<vector<int>>& res,
                           vector<int> &temp) {
        if (it == arr.size()) {
            res.push_back(temp);
            return;
        }

        temp.push_back(arr[it]);
        generateAllSubset(arr, it + 1, res, temp);
        temp.pop_back();
        generateAllSubset(arr, it + 1, res, temp);
    }
};
