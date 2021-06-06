/*
Leetcode: 845 Longest Mountain in Array

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain.
Return 0 if there is no mountain subarray.

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
*/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res = 0;

        for (int it = 1; it < arr.size() - 1; ) {
            if (isPeak(arr, it)) {
                int left = it;
                int right = it;

                while (left > 0 && arr[left] > arr[left - 1]) {
                    left--;
                }
                while (right < arr.size() - 1 && arr[right] > arr[right + 1]) {
                    right++;
                }

                res = max(res, right - left + 1);
                it = right;
            }
            else
                it++;
        }

        return res;
    }

    bool isPeak(vector<int>& arr, int index) {
        return (arr[index] > arr[index - 1]) && (arr[index] > arr[index + 1]);
    }
};
