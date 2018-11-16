/*
Q-URL: https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
# BEATS 97.64%
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        
        auto ha = headA, hb = headB;
        int la = 1, lb = 1;
        
        while ((ha = ha->next)) ++la;
        while ((hb = hb->next)) ++lb;
        
        if (la < lb) while (la++ < lb) headB = headB->next;
        else if (la > lb) while (la-- > lb) headA = headA->next;
        
        while (headA && headB)
        {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};
