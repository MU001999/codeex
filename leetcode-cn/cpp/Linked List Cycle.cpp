/*
Q-URL: https://leetcode-cn.com/problems/linked-list-cycle/description/
BEATS 100%
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto slow = head, quick = head;
        while (quick && quick->next) {
            quick = quick->next->next;
            slow = slow->next;
            if (slow == quick) return true;
        }
        return false;
    }
};
