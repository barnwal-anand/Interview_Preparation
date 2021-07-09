/*
LeetCode: 108 Convert Sorted Array to Binary Search Tree
Given an integer array nums where the elements are sorted in ascending order,
convert it to a height-balanced binary search tree.

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
[0,-10,5,null,-3,null,9] is also accepted:
*/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTUtil(nums, 0, nums.size()-1);
    }

    TreeNode* sortedArrayToBSTUtil(vector<int>& nums, int start, int end) {
        if (start > end)
            return NULL;

        int mid = start + (end - start)/2;
        TreeNode *root = new TreeNode(nums[mid]);

        root->left = sortedArrayToBSTUtil(nums, start, mid - 1);
        root->right = sortedArrayToBSTUtil(nums, mid + 1, end);

        return root;
    }
};
