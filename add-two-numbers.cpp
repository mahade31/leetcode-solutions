/*
Problem: https://leetcode.com/problems/add-two-numbers/

Solution 1:

Editorial:
Assuming you have a basic understanding of singly linked lists.
In this problem, we are asked to add two numbers. But the numbers are represented
as linked lists where the values of the nodes are the digits of a number.

There can be two cases..
1. Length or number of digits of the two numbers are same
2. They are not the same

We need to handle both of the cases, first, we will keep adding and storing until we reach the end of any number. Then we operate only on the single number that has any digit left.

From basic math, we know while adding, there can be carried. Initially, the carry is 0. We add two digits and the carry. If the resulting sum is greater than 9 then we need to carry 1 for the next add operation, and the resulting digit is sum % 10.

We also do this for the single number left.

And lastly, if the carry is left, we put that into the resulting sum.

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
