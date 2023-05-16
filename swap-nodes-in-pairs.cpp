//problem: https://leetcode.com/problems/swap-nodes-in-pairs

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
    ListNode* swap(ListNode* prev_prev, ListNode* prev, ListNode* cur){
        ListNode* temp = prev;
        prev->next = cur->next;
        cur->next = temp;
        if (prev_prev != NULL){
            prev_prev -> next = cur;
        }
        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        if (head and head->next)
            head = head->next;
        int len = 0;
        ListNode* prev, cur;
        ListNode* prev_prev = NULL;

        while (temp != NULL){
            ++len;
            if (len & 1) prev = temp;
            else {
                ListNode* cur = temp;
                temp = swap(prev_prev, prev, cur);
                prev_prev = temp;
            }
            temp = temp -> next;
        }

        return head;
    }
};
