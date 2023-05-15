//problem: https://leetcode.com/problems/swapping-nodes-in-a-linked-list

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
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while (temp != NULL){
            ++len;
            temp = temp->next;
        }
        int i = k;
        int j = len - k + 1;
        if (i > j)
            swap(i, j);
        
        int val_i, val_j;
        temp = head;
        len = 0;
        while (temp != NULL){
            ++len;
            if (len == i) val_i = temp->val;
            if (len == j) val_j = temp->val;
            temp = temp->next;
        }

        temp = head;
        len = 0;
        while (temp != NULL){
            ++len;
            if (len == i) temp->val = val_j;
            if (len == j) temp->val = val_i;
            temp = temp->next;
        }

        return head;
    }
};
