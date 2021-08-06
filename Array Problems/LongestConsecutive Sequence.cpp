/*
Leetcode: 128 Longest Consecutive Sequence
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> u_set;
        int res = 0;
        int count = 0;

        for (int num : nums) {
            u_set.insert(num);
        }

        for (int num : nums) {
            if (u_set.find(num-1) == u_set.end()) {
                while (u_set.find(num) != u_set.end()) {
                    count++;
                    num++;
                }
                res = max(count, res);
                count = 0;
            }
        }

        return res;
    }
};
