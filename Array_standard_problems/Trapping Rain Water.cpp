/*
Leetcode: 42 Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;

        if (n < 3)
            return 0;

        vector<int> left_max(n);
        vector<int> right_max(n);

        left_max[0] = height[0];
        right_max[n-1] = height[n-1];

        for (int it = 1; it < n; it++) {
            left_max[it] = max(height[it], left_max[it-1]);
        }

        for (int it = n-2; it >= 0; it--) {
            right_max[it] = max(height[it], right_max[it+1]);
        }

        for (int it = 0; it < n; it++) {
            res += min(left_max[it], right_max[it]) - height[it];
        }

        return res;
    }
};
