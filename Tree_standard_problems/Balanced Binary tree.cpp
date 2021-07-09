/*
LeetCode: 110 Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
*/

// O(n^2) solution
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        
        int lH = height(root->left);
        int rH = height(root->right);

        bool leftBalanced = isBalanced(root->left);
        bool rightBalanced = isBalanced(root->right);

        return (abs(lH-rH) <= 1) && leftBalanced && rightBalanced;
    }

    int height(TreeNode* root) {
        if (!root)
            return 0;

        return max(height(root->left), height(root->right)) + 1;
    }
};

// O(n) solution
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;

        int height = 0;
        return isBalancedUtil(root, height);
    }

    bool isBalancedUtil(TreeNode* root, int &height) {
        int lH = 0;
        int rH = 0;

        if (!root) {
            height = 0;
            return true;
        }

        bool leftBalanced = isBalancedUtil(root->left, lH);
        bool rightBalanced = isBalancedUtil(root->right, rH);
        height = max(lH, rH) + 1;

        return (abs(lH - rH) <= 1) && leftBalanced && rightBalanced;
    }
};
