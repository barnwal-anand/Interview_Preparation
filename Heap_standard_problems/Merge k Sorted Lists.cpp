/*
LeetCode: 23 Merge k Sorted Lists
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
*/

class myComparator {
    public:
    bool operator() (const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy;
        ListNode *head = &dummy;

        priority_queue<ListNode*, vector<ListNode*>, myComparator> pq;

        for (ListNode *node : lists) {
            if (node) {
                pq.push(node);
            }
        }

        while (!pq.empty()) {
            ListNode *cur = pq.top();
            pq.pop();

            head->next = cur;
            head = head->next;

            if (cur->next) {
                pq.push(cur->next);
            }
        }

        return dummy.next;
    }
};
