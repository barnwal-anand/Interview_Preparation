/*
LeetCode: 581. Shortest Unsorted Continuous Subarray
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int lmin = INT_MAX;
        int lmax = INT_MIN;
        int start = 0;
        int end = nums.size() - 1;

        if (nums.size() == 1)   return 0;

        for (int it = 0; it < nums.size(); it++) {
            if (isOutofOrder(nums, it)) {
                if (nums[it] < lmin) {
                    lmin = nums[it];
                }
                if (nums[it] > lmax) {
                    lmax = nums[it];
                }
            }
        }

        if (lmin == INT_MAX) {
            return 0;
        }

        while (nums[start] <= lmin) {
            start++;
        }

        while (lmax <= nums[end]) {
            end--;
        }

        return (end - start + 1);
    }
};

bool isOutofOrder(vector<int>& nums, int index) {
    if (index == 0) {
        return nums[index] > nums[index + 1];
    }

    if (index == nums.size() - 1) {
        return nums[index] < nums[index-1];
    }

    return (nums[index] > nums[index+1]) || (nums[index] < nums[index-1]);
}
