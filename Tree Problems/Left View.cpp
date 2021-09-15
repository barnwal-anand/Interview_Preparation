/*
Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8
*/

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
void leftViewUtil(Node *root, int height, vector<int> &res, int &max_height) {
    if (!root) {
        return;
    }

    if (max_height < height) {
        res.push_back(root->data);
        max_height = height;
    }

    leftViewUtil(root->left, height + 1, res, max_height);
    leftViewUtil(root->right, height + 1, res, max_height);
}

vector<int> leftView(Node *root) {
    vector<int> res;
    int max_height = 0;
    leftViewUtil(root, 1, res, max_height);

    return res;
}
