/*
Leetcode: 70. Climbing Stairs
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
*/

class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> dict;

        return climbStairsUtil(dict, n);
    }

    int climbStairsUtil(unordered_map<int, int> &dict, int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        if (dict.find(n) != dict.end()) {
            return dict[n];
        }

        int left = climbStairsUtil(dict, n -1);
        int right = climbStairsUtil(dict, n - 2);
        dict[n] = left + right;

        return dict[n];
    }
};
