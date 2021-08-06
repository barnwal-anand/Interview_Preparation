/*
Given a BST, and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST.
Input:
             20
            /   \
           8     22
          / \
         4   12
            /  \
           10   14
K(data of x) = 8
Output: 10
Explanation:
Inorder traversal: 4 8 10 12 14 20 22
Hence, successor of 8 is 10.
*/

class Solution{
  public:
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node *successor = NULL;

        while (root) {
            if (root->data > x->data) {
                successor = root;
            }

            if (x->data < root->data) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }

        return successor;
    }
};
