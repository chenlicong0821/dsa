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
        ListNode* p = head;
        vector<int> ret;
        while (p) {
            ret.push_back(p->val);
            p = p->next;
        }

        int i = 0, j = ret.size() - 1;
        int temp;
        while (i < j) {
            temp = ret[i];
            ret[i++] = ret[j];
            ret[j--] = temp;
        }
        return ret;
    }
};