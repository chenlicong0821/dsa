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
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode res = new ListNode(-1);
        if (lists == null || lists.length == 0) {
            return res.next;
        }
        // 表示此链表是否已经全加上去
        boolean[]  traverses = new boolean[lists.length];
        int min = Integer.MAX_VALUE;
        // 记录本轮的最小值在哪个地方
        int minPos = -1;
        // 已经遍历完成的链表的数量
        int traverseCnt = 0;

        ListNode head = res;

        while (traverseCnt < lists.length) {
            for (int i = 0; i < lists.length; i++) {
                // 第i条链表还未全部加上去
                if (!traverses[i]) {
                    // 第i条链表已经到了null，说明已经全部加上去了
                    if (lists[i] == null) {
                        traverses[i] = true;
                        traverseCnt++;
                        continue;
                    }
                    if (min > lists[i].val) {
                        min = lists[i].val;
                        minPos = i;
                    }
                }
            }
            if (min != Integer.MAX_VALUE) {
                res.next = lists[minPos];
                res = res.next;
                lists[minPos] = lists[minPos].next;
                min = Integer.MAX_VALUE;
            }
        }
        return head.next;
    }
}
