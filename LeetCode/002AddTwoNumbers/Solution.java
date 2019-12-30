/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }

        ListNode firstPre = new ListNode(-1);
        ListNode tmp = firstPre;
        int carry = 0;

        while (l1 != null && l2 != null) {
            int sum = l1.val + l2.val + carry;
            tmp.next = new ListNode(sum%10);
            tmp = tmp.next;
            carry = sum/10;
            l1 = l1.next;
            l2 = l2.next;
        }

        while (l1!=null) {
            int sum = l1.val + carry;
            tmp.next = new ListNode(sum%10);
            tmp = tmp.next;
            carry = sum/10;
            l1 = l1.next;
        }

        while (l2!=null) {
            int sum = l2.val + carry;
            tmp.next = new ListNode(sum%10);
            tmp = tmp.next;
            carry = sum/10;
            l2 = l2.next;
        }

        if (carry > 0) {
            tmp.next = new ListNode(carry);
        }

        return firstPre.next;
    }
}