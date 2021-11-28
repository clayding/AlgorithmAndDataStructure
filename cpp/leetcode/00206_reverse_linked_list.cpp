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
        ListNode* prev = NULL;
        ListNode* next = NULL;

        if (head == nullptr) {
            return nullptr;
        }

        prev = head;
        next = head->next;

        while (next != nullptr) {
            ListNode* tmp = next->next;
            next->next = prev;
            prev = next;
            next = tmp;
        }

        head->next = NULL;
        return prev;
    }
};