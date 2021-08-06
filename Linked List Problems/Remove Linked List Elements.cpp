/*
Leetcode: 203 Remove Linked List Elements

Given the head of a linked list and an integer val,
remove all the nodes of the linked list that has Node.val == val, and return the new head.

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur = head;
        ListNode *prev = NULL;

        while (cur) {
            if (cur->val == val) {
                //head val matches with val
                if (prev == NULL) {
                    head = head->next;
                    cur = cur->next;
                }
                else {
                    prev->next = cur->next;
                    delete(cur);
                    cur = prev->next;
                }
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }

        return head;
    }
};
