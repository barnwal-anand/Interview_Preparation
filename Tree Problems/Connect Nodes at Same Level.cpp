/*
Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.

Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.
       10                       10 ------> NULL
      / \                       /      \
     3   5       =>     3 ------> 5 --------> NULL
    / \     \               /  \           \
   4   1   2          4 --> 1 -----> 2 -------> NULL
*/

/*
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */


class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root) {
       queue<Node *> q;
       Node *prev = root;

       q.push(root);
       q.push(NULL);

       while(!q.empty()) {
           Node *cur = q.front();
           q.pop();

           if (prev) {
               prev->nextRight = cur;
           }
           prev = cur;

           if (!cur) {
               if (!q.empty()) {
                   q.push(NULL);
               }
           }
           else {
               if (cur->left) {
                   q.push(cur->left);
               }
               if (cur->right) {
                   q.push(cur->right);
               }
           }
       }
   }
};
