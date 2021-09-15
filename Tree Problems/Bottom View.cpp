/*
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
*/

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> res;
        map<int, pair<int, int>> m;

        bottomViewHelper(root, m, 0, 0);

        for (auto temp : m) {
            res.push_back(temp.second.first);
        }

        return res;
    }

    void bottomViewHelper(Node *root, map<int, pair<int, int>> &m, int index, int level) {
        if (!root)
            return;

        if (level >= m[index].second) {
            m[index] = {root->data, level};
        }

        bottomViewHelper(root->left, m, index - 1, level + 1);
        bottomViewHelper(root->right, m, index + 1, level + 1);
    }
};
