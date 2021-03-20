import java.util.*;

/*
 * public class ListNode {
 *   int val;
 *   ListNode next = null;
 * }
 */

public class Solution {
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    public ListNode sortList (ListNode head) {
        if (head==null || head.next==null) {
            return head;
        }

        ListNode slow = head;
        ListNode fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode listB = sortList(slow.next);
        slow.next = null;
        ListNode listA = sortList(head);
        return merge(listA, listB);
    }

    private ListNode merge(ListNode listA, ListNode listB) {
        ListNode dummy = new ListNode(0);
        ListNode nodeA = listA;
        ListNode nodeB = listB;
        ListNode nodeR = dummy;
        while (nodeA != null && nodeB != null){
            if (nodeA.val < nodeB.val) {
                nodeR.next = nodeA;
                nodeA = nodeA.next;
            } else {
                nodeR.next = nodeB;
                nodeB = nodeB.next;
            }
            nodeR = nodeR.next;
        }
        if (nodeA != null) {
            nodeR.next = nodeA;
        }
        if (nodeB != null) {
            nodeR.next = nodeB;
        }

        return dummy.next;
    }
}