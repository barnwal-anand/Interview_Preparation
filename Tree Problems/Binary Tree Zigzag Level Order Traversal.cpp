/*
Leetcode: 103 Binary Tree Zigzag Level Order Traversal
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
(i.e., from left to right, then right to left for the next level and alternate between).

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
*/

// Using queue and store each level in vector
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> level;
        queue<TreeNode*> q;
        int leftOrder = 0;
        if (!root)  return res;

        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();

            if (!temp) {
                if (leftOrder) {
                    reverse(level.begin(), level.end());
                }
                res.push_back(level);
                level.clear();
                leftOrder = 1 - leftOrder;
                if (!q.empty()) {
                    q.push(NULL);
                }
            }
            else {
                level.push_back(temp->val);

                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
        }
        return res;
    }
};

// Using 2 stack
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> level;
        stack<TreeNode*> currentLevel;
        stack<TreeNode*> nextLevel;
        int leftToRight = 1;

        if (!root)  return res;

        currentLevel.push(root);

        while (!currentLevel.empty()) {
            TreeNode *temp = currentLevel.top();
            currentLevel.pop();

            if (temp) {
                level.push_back(temp->val);
                if (leftToRight) {
                    if (temp->left) {
                        nextLevel.push(temp->left);
                    }
                    if (temp->right) {
                        nextLevel.push(temp->right);
                    }
                }
                else {
                    if (temp->right) {
                        nextLevel.push(temp->right);
                    }
                    if (temp->left) {
                        nextLevel.push(temp->left);
                    }
                }
            }

            if (currentLevel.empty()) {
                leftToRight = 1 - leftToRight;
                swap(currentLevel, nextLevel);
                res.push_back(level);
                level.clear();
            }
        }
        return res;
    }
};
