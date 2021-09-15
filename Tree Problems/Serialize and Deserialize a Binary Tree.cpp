/*
Serialization is to store a tree in an array so that it can be later restored and
Deserialization is reading tree back from the array.
Note: The structure of tree must be maintained.

Input:
         10
       /    \
      20    30
    /   \
   40  60
Output: 40 20 60 10 30
*/
    vector<int> serialize(Node *root) {
        vector<int> res;
        serializeUtil(root, res);

        return res;
    }
    void serializeUtil(Node *root, vector<int> &res) {
        if (!root) {
            res.push_back(-1);
            return;
        }

        res.push_back(root->data);
        serializeUtil(root->left, res);
        serializeUtil(root->right, res);
    }

    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A) {
       Node *root = NULL;
       int index = 0;
       deSerializeUtil(root, A, index);

       return root;
    }

    void deSerializeUtil(Node* &root, vector<int> &A, int &index) {
        if (A[index] == -1) {
            root = NULL;
            return;
        }

        root = newNode(A[index]);
        index += 1;
        deSerializeUtil(root->left, A, index);
        index += 1;
        deSerializeUtil(root->right, A, index);
    }
