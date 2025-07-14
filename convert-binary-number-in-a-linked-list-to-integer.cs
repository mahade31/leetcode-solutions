//problem: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    
    public int GetDecimalValue(ListNode head) {
        var num = 0;
        var len = -1;
        var start = head;
        while (start is not null) {
            ++len;
            start = start.next;
        }

        start = head;

        while (start is not null) {
            num = num + start.val * (1 << len);
            start = start.next;
            --len;
        }

        return num;
    }
}