/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // res, fast, slow均指向第0个节点，res.next是第1个节点即头结点
        ListNode res = new ListNode(-1);
        res.next = head;
        ListNode fast = res;
        ListNode slow = res;

        // 使fast指向第n个节点
        while(n-- > 0) {
            fast = fast.next;
        }
        // 使fast指向倒数第1个节点，slow指向倒数第n+1个节点
        while(fast.next != null){
            slow = slow.next;
            fast = fast.next;
        }
        // slow此时指向倒数第n+1个节点，删除倒数第n个节点
        slow.next = slow.next.next;

        return res.next;
    }
}