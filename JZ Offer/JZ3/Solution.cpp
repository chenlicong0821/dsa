/**
 *  struct ListNode {
 *        int val;
 *        struct ListNode *next;
 *        ListNode(int x) :
 *              val(x), next(NULL) {
 *        }
 *  };
 */
class Solution {
   public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }

        vector<int> ret;
        while (pre) {
            ret.push_back(pre->val);
            pre = pre->next;
        }
        return ret;
    }
};