#include <stdio.h>
#include <stdlib.h>

struct StackNode {
      int data;
      struct StackNode *next;
};

struct StackNode* getStackNode(int num) {
      struct StackNode *newNode = (struct StackNode *) malloc(sizeof(struct StackNode));
      newNode -> data = num;
      newNode -> next = NULL;
      return newNode;
}

void push(struct StackNode **sNode, int num) {
      struct StackNode *newNode = getStackNode(num);
      newNode -> next = *sNode;
      *sNode = newNode;
}

int pop(struct StackNode **sNode) {
      if(*sNode == NULL) {
            printf("Stack Empty: ");
            return -1;
      }
      struct StackNode *temp = *sNode;
      *sNode = (*sNode) -> next;
      int data = temp -> data;
      free(temp);
      return data;
}

int main() {
      struct StackNode *sNode = NULL;
      push(&sNode, 10);
      push(&sNode, 20);
      //push(&sNode, 30);
      printf("%d\n", pop(&sNode));
      printf("%d\n", pop(&sNode));
      printf("%d\n", pop(&sNode));
      return 0;
}
