/*
Given a BST and an integer. Find the least absolute difference between any node value of the BST and the given integer.

Input:
        10
      /   \
     2    11
   /  \
  1    5
      /  \
     3    6
      \
       4
K = 13
Output: 2
Explanation: K=13. The node that has value nearest to K is 11. so the answer is 2
*/

class Solution
{
    public:
    int minDiff(Node *root, int K)
    {
        int res = INT_MAX;

        while (root) {
            res = min(abs(root->data - K), res);

            if (K < root->data) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }

        return res;
    }
};

// recursive
class Solution
{
    public:
    int minDiff(Node *root, int K)
    {
        int res = INT_MAX;
        minDiffUtil(root, K, res);

        return res;
    }

    void minDiffUtil(Node *root, int &K, int &res) {
        if (!root)
            return;

        res = min(abs(root->data - K), res);

        if (K < root->data) {
            minDiffUtil(root->left, K, res);
        }
        else {
            minDiffUtil(root->right, K, res);
        }
    }
};
