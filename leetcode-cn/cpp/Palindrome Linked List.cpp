/*
Q-URL: https://leetcode-cn.com/problems/palindrome-linked-list/description/
# BEATS 98.88%
*/

class Solution {
public:
    
    ListNode* reverseList(ListNode *head) {
        if (!head) return head;
        auto next = head->next;
        auto reverse = head;
        if (next) {
            reverse = reverseList(next);
            next->next = head;
            head->next = NULL;
        }
        return reverse;
    }
    
    bool isPalindrome(ListNode* head) {
        auto slow = head, quick = head;
        while (quick && quick->next) {
            quick = quick->next->next;
            slow = slow->next;
        }   quick = head;
        
        slow = reverseList(slow);
        while (slow) {
            if (slow->val != quick->val) return false;
            slow = slow->next;
            quick = quick->next;
        }
        
        return true;
    }
};
