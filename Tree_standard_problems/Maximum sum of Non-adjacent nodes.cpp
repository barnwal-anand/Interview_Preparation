/*
Given a binary tree with a value associated with each node,
we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint
that no two chosen node in subset should be directly connected that is,
if we have taken a node in our sum then we can’t take its any children in consideration and vice versa.

Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of nodes 1 4 5 6 , i.e 16
*/
//Function to return the maximum sum of non-adjacent nodes.
int getMaxSum(Node *root)
{
    if (!root)
        return 0;

    int inc = 0;
    int exc = 0;

    getMaxSumUtil(root, inc, exc);

    return max(inc, exc);
}

void getMaxSumUtil(Node *root, int &include, int &exclude)
{
    int lInc = 0, lExc = 0;
    int rInc = 0, rExc = 0;

    if (!root) {
        include = 0;
        exclude = 0;
        return;
    }

    getMaxSumUtil(root->left, lInc, lExc);
    getMaxSumUtil(root->right, rInc, rExc);

    //if root is included
    include = root->data + lExc + rExc;

    //if root is exclude
    exclude = max(lInc, lExc) + max(rInc, rExc);
}
