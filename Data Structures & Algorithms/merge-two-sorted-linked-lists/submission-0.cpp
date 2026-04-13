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
        if (list1 == nullptr && list2 == nullptr) { return nullptr; }
        if (list1 == nullptr) { return list2; }
        if (list2 == nullptr) { return list1; }

        ListNode *root, *prev, *it;

        if (list1->val <= list2->val) { 
            it = new ListNode(list1->val, list1->next);
            list1 = list1->next;
        } else {
            it = new ListNode(list2->val, list2->next);
            list2 = list2->next;
        }

        root = prev = it;

        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {
                it = new ListNode(list1->val, list1->next);
                list1 = list1->next;
            } else {
                it = new ListNode(list2->val, list2->next);
                list2 = list2->next;
            }

            prev->next = it;
            prev = it;
        }

        if (list1 != nullptr) {
            while (list1 != nullptr) {
                it = new ListNode(list1->val, list1->next);
                list1 = list1->next;
                prev->next = it;
                prev = it;
            }
        }

        if (list2 != nullptr) {
            while (list2 != nullptr) {
                it = new ListNode(list2->val, list2->next);
                list2 = list2->next;
                prev->next = it;
                prev = it;
            }
        }

        return root;
    }
};
