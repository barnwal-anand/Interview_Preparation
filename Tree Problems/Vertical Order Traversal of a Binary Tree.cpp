/*
Leetcode: 987 Vertical Order Traversal of a Binary Tree

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1)
and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> tMap;
        vector<vector<int>> res;

        if (!root)
            return res;

        verticalTraversalUtil(root, 0, 0, tMap);

        map<int, map<int, multiset<int>>>::iterator it;

        for(it = tMap.begin(); it != tMap.end(); it++) {
            vector<int> col;

            for (auto allColNums : it->second) {
                col.insert(col.end(),
                           allColNums.second.begin(), allColNums.second.end());
            }

            res.push_back(col);
        }

        return res;
    }

    void verticalTraversalUtil(TreeNode* root, int row, int col,
                               map<int, map<int, multiset<int>>> &tMap) {
        if (!root)
            return;

        verticalTraversalUtil(root->left, row + 1, col - 1, tMap);
        verticalTraversalUtil(root->right, row + 1, col + 1, tMap);

        tMap[col][row].insert(root->val);
    }
};
