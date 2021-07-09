/*
Given an array of elements, the task is to insert these elements in level order and construct a tree.

Input : arr[] = {10, 20, 30, 40, 50, 60}
Output :         10
              /      \
             20       30
            /  \     /
          40    50  60
*/

Node* createTree(vector<int> arr) {
	if (!arr.size())
		return NULL;

	queue<Node*> q;
	Node *root = newNode(arr[0]);
	q.push(root);
	int it = 0;

	while (1) {
		Node* temp = q.front();
		q.pop();
		int lIndex = it + 1;
		int rIndex = it + 2;

		if (lIndex == arr.size()) {
			break;
		}

		if (arr[lIndex] != -1) {
			temp->left = newNode(arr[lIndex]);
			q.push(temp->left);
		}

		if (arr[rIndex] != -1) {
			temp->right = newNode(arr[it + 2]);
			q.push(temp->right);
		}

		it += 2;
	}

	return root;
}
