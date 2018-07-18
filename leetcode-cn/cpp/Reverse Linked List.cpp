/*
Q-URL: https://leetcode-cn.com/problems/reverse-linked-list/description/
# ALL BEATS 99.25%
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        vector<ListNode*> nodes = {head};
        auto temp = head;
        while ((temp = temp->next)) nodes.push_back(temp);
        for (int i = nodes.size() - 1; i > 0; --i) nodes[i]->next = nodes[i-1];
        nodes[0]->next = NULL;
        return nodes[nodes.size()-1];
    }
};

//-------------------------------------------------------------

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
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
};
