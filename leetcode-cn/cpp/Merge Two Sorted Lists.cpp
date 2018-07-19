/*
Q-URL: https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
# BEATS 99.97%
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *hhead = new ListNode(0);
        auto head = hhead;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                head->next = l1;
                head = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                head = l2;
                l2 = l2->next;
            }   head->next = NULL;
        }
        head->next = l1 ? l1 : l2;
        return hhead->next;
    }
};
