/*
Q-URL: https://leetcode-cn.com/problems/add-two-numbers/
# BEATS 99%
*/


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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        if (l1 == nullptr && l2 == nullptr) {
            if (carry) {
                return new ListNode(carry);
            }
            return nullptr;
        } else if (l1 == nullptr || l2 == nullptr) {
            if (l1 == nullptr) {
                swap(l1, l2);
            }

            if (carry == 0) {
                return l1;
            }

            auto sum = l1->val + carry;
            l1->val = sum % 10;
            l1->next = addTwoNumbers(l1->next, l2, sum / 10);
            return l1;
        }

        auto sum = l1->val + l2->val + carry;
        l1->val = sum % 10;
        l1->next = addTwoNumbers(l1->next, l2->next, sum / 10);
        return l1;
    }   
};
