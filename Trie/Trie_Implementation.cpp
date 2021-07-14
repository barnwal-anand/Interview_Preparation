#include <iostream>
using namespace std;
#define CHAR_SIZE 26
void printAutoSuggestions(struct Trie *root, const string query);
void printAutoSuggestionsUtil(struct Trie *root, const string key);
bool isLastNode(struct Trie* root);

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
	insert(root, "hello");
	insert(root, "dog");
	insert(root, "hell");
	insert(root, "cat");
	insert(root, "a");
	insert(root, "hel");
	insert(root, "help");
	insert(root, "helps");
	insert(root, "helping");

	cout << search(root, "cat") << endl;
	cout << search(root, "car") << endl;

	printAutoSuggestions(root, "hel");

	return 0;
}

void printAutoSuggestions(struct Trie *root, const string query)
{
	struct Trie *cur = root;

	for(int it = 0; it < query.length(); it++) {
		int index = query[it] - 'a';
		if (!cur->child[index]) {
			// query does not exist in trie
			cout << query << " - does not exist in trie" << endl;
			return;
		}
		cur = cur->child[index];
	}

	printAutoSuggestionsUtil(cur, query);
}

void printAutoSuggestionsUtil(struct Trie *root, const string key)
{
	if (root->isEndOfWord) {
		cout << key << endl;
	}
	if (isLastNode(root)) {
		return;
	}

	for (int it = 0; it < CHAR_SIZE; it++) {
		if (root->child[it]) {
			char ch = it + 'a';
			printAutoSuggestionsUtil(root->child[it], key + ch);
		}
	}
}

bool isLastNode(struct Trie* root)
{
	for (int it = 0; it < CHAR_SIZE; it++)
		if (root->child[it])
			return 0;
	return 1;
}
