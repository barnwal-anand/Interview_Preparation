Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6 // [4,-1,2,1] has the largest sum = 6

// Simple greedy approach
// Pick the locally optimal move at each step, and that will lead to the globally optimal solution.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curMax = nums[0];

        for (int it = 1; it < nums.size(); it++)
        {
            curMax = max(nums[it], curMax + nums[it]);
            maxSum = max(maxSum, curMax);
        }

        return maxSum;
    }
};
