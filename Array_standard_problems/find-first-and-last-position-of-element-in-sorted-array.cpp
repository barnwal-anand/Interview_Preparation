/*
Leetcode: 34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lowBound = lowboundSearch(nums, target);
        int highBound = highboundSearch(nums, target);

        return {lowBound, highBound};
    }

    int lowboundSearch(vector<int>& arr, int key) {
        int l = 0;
        int h = arr.size() - 1;
        int res = -1;

        while (l <= h) {
            int mid = (l + h)/2;

            if (key == arr[mid]) {
                res = mid;
                h = mid - 1;
            }
            else if (key < arr[mid]) {
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return res;
    }

    int highboundSearch(vector<int>& arr, int key) {
        int l = 0;
        int h = arr.size() - 1;
        int res = -1;

        while (l <= h) {
            int mid = (l + h)/2;

            if (key == arr[mid]) {
                res = mid;
                l = mid + 1;
            }
            else if (key < arr[mid]) {
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return res;
    }
};
