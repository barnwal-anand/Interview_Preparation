/*
Convert a given tree to its Sum Tree
Given a Binary Tree where each node has positive and negative values.
Convert this to a tree where each node contains the sum of the left and right sub trees in the original tree.
The values of leaf nodes are changed to 0.
For example, the following tree


                  10
               /      \
             -2        6
           /   \      /  \
         8     -4    7    5
should be changed to


                 20(4-2+12+6)
               /      \
         4(8-4)      12(7+5)
           /   \      /  \
         0      0    0    0
*/

int toSumTree(Node *node)
{
	if (!node)
		return 0;

	int lSum = toSumTree(node->left);
	int rSum = toSumTree(node->right);

	int temp = node->data;
	node->data = lSum + rSum;
	return lSum + rSum + temp;
}
