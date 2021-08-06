/*
Leetcode: 33. Search in Rotated Sorted Array
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;

        while (l <= h) {
            int mid = (l + h) / 2;

            if (target == nums[mid]) {
                return mid;
            }

            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target  && target < nums[mid]) {
                    h = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && target <= nums[h]) {
                    l = mid + 1;
                }
                else {
                    h = mid - 1;
                }
            }
        }

        return -1;
    }
};
