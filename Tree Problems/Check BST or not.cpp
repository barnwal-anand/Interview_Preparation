class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        Node *prev = NULL;
        return isBSTUtil(root, prev);
    }

    bool isBSTUtil(Node* root, Node* &prev) {
        if (!root) {
            return true;
        }

        if (!isBSTUtil(root->left, prev)) {
            return false;
        }

        if (prev && root->data <= prev->data) {
            return false;
        }
        prev = root;
        return isBSTUtil(root->right, prev);
    }

};

// Another approach
int isBST(node* node)
{
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}

/* Returns true if the given tree is a BST and its values are >= min and <= max. */
int isBSTUtil(node* node, int min, int max)
{
    /* an empty tree is BST */
    if (node==NULL)
        return 1;

    /* false if this node violates
    the min/max constraint */
    if (node->data < min || node->data > max)
        return 0;

    /* otherwise check the subtrees recursively, tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values
        isBSTUtil(node->right, node->data+1, max); // Allow only distinct values
}
