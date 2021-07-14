#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *getNode(int data) {
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

void generateFib(struct Node **head, int n) {
	int prev1 = 0;
	int prev2 = 0;
	int cur = 1;
	int count = 1;

	*head = getNode(cur);
	struct Node *curNode = *head;

	while (count < n) {
		prev1 = prev2;
		prev2 = cur;
		cur = prev1 + prev2;
		curNode->next = getNode(cur);
		curNode = curNode->next;

		count++;
	}
}

int main() {
	int n = 10;
	struct Node *head = NULL;

	generateFib(&head, n);

	while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
	return 0;
}
