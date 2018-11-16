/*
Q-URL: https://leetcode-cn.com/problems/add-two-numbers/
# BEATS 97.72%
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int c = 0) 
    {
        auto pre = new ListNode(0);
        auto tmp = pre;
        
        while (l1 && l2)
        {
            tmp->next = new ListNode(l1->val + l2->val + c);
            tmp = tmp->next; l1 = l1->next; l2 = l2->next;
            c = tmp->val / 10;
            tmp->val %= 10;
        }
        
        tmp->next = c ? ((l1 || l2) ? addTwoNumbers(l1 ? l1 : l2, new ListNode(c)) : new ListNode(c)) : (l1 ? l1 : l2);
        
        return pre->next;
    }
};
