// LeetCode: 581. Shortest Unsorted Continuous Subarray
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1;
        int end = -1;

        for (int it = 0; it < nums.size() - 1; it++)
        {
            if (nums[it] > nums[it + 1])
            {
                start = it;
                break;
            }
        }

        // already sorted
        if (start == -1)
            return 0;

        for (int it = nums.size() - 1; it > 0; it--)
        {
            if (nums[it] < nums[it - 1])
            {
                end = it;
                break;
            }
        }

        int min_ = nums[start];
        int max_ = nums[start];

        for (int it = start + 1; it <= end; it++)
        {
            min_ = min(min_, nums[it]);
            max_ = max(max_, nums[it]);
        }

        for (int it = 0; it < start; it++)
        {
            if (nums[it] > min_)
            {
                start = it;
                break;
            }
        }

        for (int it = end + 1; it < nums.size(); it++)
        {
            if (nums[it] < max_)
            {
                end = it;
            }
        }

        return end - start + 1;
    }
};
