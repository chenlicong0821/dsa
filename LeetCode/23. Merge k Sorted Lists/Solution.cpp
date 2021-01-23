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
class Solution
{
public:
    struct Status
    {
        int val;
        ListNode *ptr;
        bool operator<(const Status &rhs) const
        {
            return val > rhs.val;
        }
    };

    priority_queue<Status> q;

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        for (auto node : lists)
        {
            if (node)
                q.push({node->val, node});
        }
        ListNode head, *pTail = &head;
        while (!q.empty())
        {
            auto f = q.top();
            q.pop();
            pTail->next = f.ptr;
            pTail = pTail->next;
            if (f.ptr->next)
                q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};
