/*
Leetcode: 543 Diameter of Binary Tree
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
This path may or may not pass through the root.

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3is the length of the path [4,2,1,3] or [5,2,1,3].
*/

// O(n^2)
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        int d1 = heightofBinaryTree(root->left) + heightofBinaryTree(root->right);
        int d2 = diameterOfBinaryTree(root->left);
        int d3 = diameterOfBinaryTree(root->right);

        return max(max(d1, d2), d3);
    }

    int heightofBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        return max(heightofBinaryTree(root->left), heightofBinaryTree(root->right))+1;
    }
};

//O(n) - Keep track of height in the recursion stack
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        int height = 0;
        return heightofBinaryTree(root, height);
    }

    int heightofBinaryTree(TreeNode* root, int &height) {
        int lH = 0;
        int rH = 0;

        if (!root) {
            height = 0;
            return 0;
        }

        int lDiameter = heightofBinaryTree(root->left, lH);
        int rDiameter = heightofBinaryTree(root->right, rH);
        height = max(lH, rH) + 1;

        return max(lH + rH, max(lDiameter, rDiameter));
    }
};
