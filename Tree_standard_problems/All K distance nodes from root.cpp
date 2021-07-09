/*
Given a Binary Tree of size N and an integer K.
Print all nodes that are at distance k from root
(root is considered at distance 0 from itself).
Nodes should be printed from left to right. If k is more that height of tree, nothing should be printed.

K = 3
        3
       /
      2
       \
        1
      /  \
     5    3
Output: 5 3
*/

vector<int> Kdistance(struct Node *root, int k)
{
    vector<int> res;
    KdistanceUtil(root, k, res);

    return res;
}

void KdistanceUtil(struct Node *root, int k, vector<int> &res)
{
    if (!root)
        return;

    if (k == 0)
        res.push_back(root->data);

    KdistanceUtil(root->left, k - 1, res);
    KdistanceUtil(root->right, k - 1, res);
}
