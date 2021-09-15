/*
Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.

Example 1:

Input:
              5
           /    \
         4       6
        /         \
       3           7
                    \
                     8
n1 = 7, n2 = 8
Output: 7
*/

Node* LCA(Node *root, int n1, int n2) {
   if (!root) {
       return NULL;
   }

   if (n1 < root->data && n2 < root->data) {
       return LCA(root->left, n1, n2);
   }

   if (n1 > root->data && n2 > root->data) {
       return LCA(root->right, n1, n2);
   }

   return root;
}

/*
LCA in binart tree
*/

Node *findLCA(struct Node* root, int n1, int n2)
{
    if (root == NULL) return NULL;

    // If either n1 or n2 matches with root's key
    if (root->key == n1 || root->key == n2)
        return root;

    // Look for keys in left and right subtrees
    Node *left_lca  = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);

    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)  return root;

    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL)? left_lca: right_lca;
}
