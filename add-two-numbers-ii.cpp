//problem: https://leetcode.com/problems/add-two-numbers-ii/

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
private:
void print(ListNode* cur) {
    ListNode* head = cur;
    while (head) {
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}
ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL, *temp;
    //ListNode* head = cur;
    while (head) {
        temp = head -> next;
        head -> next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* ret = new ListNode();
        int carry = 0;
        auto cur = ret;
        ListNode* prev;

        while (l1 and l2) {
            int sum = l1 -> val + l2 -> val + carry;
            cur -> val = sum % 10;
            cur -> next = new ListNode();
            carry = sum / 10;
            l1 = l1 -> next;
            l2 = l2 -> next;
            prev = cur;
            cur = cur -> next;
        }

        while (l1) {
            int sum = l1 -> val + carry;
            cur -> val = sum % 10;
            cur -> next = new ListNode();
            carry = sum / 10;
            l1 = l1 -> next;
            prev = cur;
            cur = cur -> next;
        }
        
        while (l2) {
            int sum = l2 -> val + carry;
            cur -> val = sum % 10;
            cur -> next = new ListNode();
            carry = sum / 10;
            l2 = l2 -> next;
            prev = cur;
            cur = cur -> next;
        }

        if (carry)
            cur -> val = carry;
        else
            prev -> next = NULL;

        return reverse(ret);
    }
};

//less code

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
private:
void print(ListNode* cur) {
    ListNode* head = cur;
    while (head) {
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}
ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL, *temp;
    //ListNode* head = cur;
    while (head) {
        temp = head -> next;
        head -> next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* ret = new ListNode();
        int carry = 0;
        auto cur = ret;
        ListNode* prev;

        while (l1 or l2) {
            int sum = carry;
            if (l1) {
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2) {
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            cur -> val = sum % 10;
            cur -> next = new ListNode();
            carry = sum / 10;
            prev = cur;
            cur = cur -> next;
        }

        if (carry)
            cur -> val = carry;
        else
            prev -> next = NULL;

        return reverse(ret);
    }
};
