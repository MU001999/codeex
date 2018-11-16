/*
Q-URL: https://leetcode-cn.com/problems/odd-even-linked-list/
# BEATS 99.85%
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        
        auto first = head, second = head->next, head2 = head->next;
        
        while (second && second->next)
        {
            first = first->next = second->next;
            second = second->next = second->next->next;
        }
        
        first->next = head2;
        return head;
    }
};
