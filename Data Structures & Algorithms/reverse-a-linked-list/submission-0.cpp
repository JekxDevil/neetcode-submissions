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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) { return nullptr; }

        ListNode *prev = nullptr, *pivot = head;
        while (pivot->next != nullptr) {
            ListNode *backup = pivot->next;
            pivot->next = prev;
            prev = pivot;
            pivot = backup;
        }

        pivot->next = prev;
        // return pivot;
        return pivot;
    }
};
