/*
Q-URL: https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
# ALL BEATS 100%
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes = {head};
        auto temp = head;
        while ((temp = temp->next)) nodes.push_back(temp);
        if (n >= nodes.size()) head = head->next;
        else nodes[nodes.size()-n-1]->next = nodes[nodes.size()-n]->next;
        return head;
    }
};

//---------------------------------------------------------------------------

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return NULL;
        auto pre = head, cur = head;
        while (n--) cur = cur->next;
        if (!cur) return head->next;
        while (cur->next) {
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};
