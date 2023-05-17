//problem: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    int ret;
    ListNode* first;
    void pairSum(ListNode* last, int rt) {
        if (last == NULL)
            return;
        pairSum(last->next, 0);
        int val = first->val + last -> val;
        first = first->next;
        if (first == last) return;
        ret = max(ret, val);
    }

    int pairSum(ListNode* head) {
        first = head;
        pairSum(head, 0);
        return ret;
    }
};
