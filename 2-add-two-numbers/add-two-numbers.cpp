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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *first = l1, *second = l2;
        int sum = first->val + second->val;
        int val = sum % 10, carry = sum / 10;
        ListNode* newList = new ListNode(val);
        ListNode* curr = newList;
        first = first->next;
        second = second->next;
        while(first && second) {
            sum = first->val + second->val + carry;
            val = sum % 10;
            carry = sum / 10;
            curr->next = new ListNode(val);
            curr = curr->next;
            first = first->next;
            second = second->next;
        }
        while (first) {
            sum = first->val + carry;
            val = sum % 10;
            carry = sum / 10;
            curr->next = new ListNode(val);
            curr = curr->next;
            first = first->next;
        }
        while (second) {
            sum = second->val + carry;
            val = sum % 10;
            carry = sum / 10;
            curr->next = new ListNode(val);
            curr = curr->next;
            second = second->next;
        }
        if (carry) {
            curr->next = new ListNode(carry);
        }
        return newList;
    }
};