/*
Q-URL: https://leetcode-cn.com/problems/remove-linked-list-elements/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto headpre = new ListNode(0);
        headpre->next = head;
        
        auto pre = headpre, now = headpre->next;
        while (now) if (now->val == val) tie(pre->next, now) = make_tuple(now->next, now->next); else tie(pre, now) = make_tuple(pre->next, now->next);
        
        return headpre->next;
    }
};
