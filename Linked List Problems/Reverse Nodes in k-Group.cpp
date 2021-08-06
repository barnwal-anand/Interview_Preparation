/*
LeetCode: 25 Reverse Nodes in k-Group
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k < 2 || !head || !head->next) {
            return head;
        }

        ListNode *cur = head;
        ListNode *prev = NULL;
        ListNode *next;
        int count = 0;
        int len = getLen(head);

        if (k <= len) {
            while (count < k && cur) {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
                count++;
            }

            if (next) {
                head->next = reverseKGroup(next, k);
            }
        }
        else {
            return head;
        }

        return prev;
    }

    int getLen(ListNode *head)
    {
        int count = 0;
        while (head)
        {
            count++;
            head = head->next;
        }

        return count;
    }
};
