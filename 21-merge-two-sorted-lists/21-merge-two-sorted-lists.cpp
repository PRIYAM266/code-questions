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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL)
            return NULL;
        else if (list1 == NULL)
            return list2;
        else if (list2 == NULL)
            return list1;
        // ListNode* mergeList;
        ListNode *mergeList = new ListNode(-1, nullptr);
        ListNode* head = mergeList;
        // if (list1->val <= list2->val) {
        //     mergeList = list1;
        // } else {
        //     mergeList = list2;
        // }
        while(list1 && list2) {
            if (list1->val < list2->val) {
                mergeList->next = list1;
                list1 = list1->next;
            } else {
                mergeList->next = list2;
                list2 = list2->next;
            }
            mergeList = mergeList->next;
        }
        if (list1) mergeList->next = list1;
        if (list2) mergeList->next = list2;
        return head->next;
        
    }
};