#include <iostream>
using namespace std;
#define CHAR_SIZE 26

struct Trie {
	bool isEndOfWord;
	struct Trie *child[CHAR_SIZE];
};

struct Trie* getTrieNode() {
	struct Trie *newNode = new Trie;
	newNode->isEndOfWord = false;
	for (int it = 0; it < CHAR_SIZE; it++) {
		newNode->child[it] = NULL;
	}

	return newNode;
};

void insert(struct Trie *root, string word) {
	struct Trie *cur = root;

	for (int it = 0; it < word.length(); it++) {
		int index = word[it] - 'a';
		if (!cur->child[index]) {
			cur->child[index] = getTrieNode();
		}

		cur = cur->child[index];
	}

	cur->isEndOfWord = true;
}

bool search(struct Trie *root, string word) {
	if (!root)
		return false;

	struct Trie *cur = root;
	for (int it = 0; it < word.length(); it++) {
		int index = word[it] - 'a';
		if (!cur->child[index]) {
			return false;
		}
		cur = cur->child[index];
	}

	return cur->isEndOfWord;
}

int main() {
	struct Trie *root = getTrieNode();
	insert(root, "cat");
	insert(root, "dog");
	insert(root, "cow");

	cout << search(root, "cow") << endl;
	cout << search(root, "car") << endl;

	return 0;
}
