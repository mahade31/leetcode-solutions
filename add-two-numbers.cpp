/*
Editorial:
Assuming you have the basic understanding of singly linked list.
In this problem we are asked to add two numbers. But the numbers are represented
as linked lists where the values of the nodes are the digits of a number.



*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode();
        ListNode* head = l3;
        int carry = 0;
        
        while (l1 != NULL and l2 != NULL){
            l3 -> next = new ListNode();
            int temp = l1 -> val + l2 -> val + carry;
            if (temp > 9){
                carry = 1;
                l3 -> val = temp % 10;
            }
            else {
                l3 -> val = temp;
                carry = 0;
            }
            
            l1 = l1 -> next;
            l2 = l2 -> next;
            if (l1 != NULL or l2 != NULL)
                l3 = l3 -> next; 
        }
        
        while (l1 != NULL){
            l3 -> next = new ListNode();
            int temp = l1 -> val + carry;
            if (temp > 9){
                carry = 1;
                l3 -> val = temp % 10;
            }
            else {
                l3 -> val = temp;
                carry = 0;
            }
            
            l1 = l1 -> next;
            if (l1 != NULL)
                l3 = l3->next;
        }
        
        while (l2 != NULL){
            l3 -> next = new ListNode();
            int temp = l2 -> val + carry;
            if (temp > 9){
                carry = 1;
                l3 -> val = temp % 10;
            }
            else {
                l3 -> val = temp;
                carry = 0;
            }
            
            l2 = l2 -> next;
            if (l2 != NULL)
                l3 = l3 -> next;
        }
        
        if (carry)
            l3 -> next -> val = carry;
        else
            l3 -> next = NULL;
        
        return head;
    }
};
