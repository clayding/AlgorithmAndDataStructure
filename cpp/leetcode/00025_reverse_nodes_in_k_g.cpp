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
    ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode *dummyNode = new ListNode(0);
            ListNode *prev = nullptr;
            ListNode *next = nullptr;
            ListNode *last = head;
            int cnt = 0;

            if (head == nullptr) {
                return head;
            }

            for(int i = 0;i < k;i++){
                if(last == NULL) return head;
                last = last->next;
            }

            dummyNode->next = head;
            prev = head;
            next = head;

            while (next != nullptr && cnt < k) {
                ListNode *temp = next->next;
                next->next = prev;
                prev = next;
                next = temp;
                cnt++;
            }

            dummyNode->next->next = reverseKGroup(next, k);
            return prev;
    }
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode *dummyNode = new ListNode(0);
            ListNode *prev = nullptr;
            ListNode *next = nullptr;
            int cnt = 0;

            if (head == nullptr) {
                return head;
            }

            dummyNode->next = head;
            prev = dummyNode->next;
            next = dummyNode->next;

            while (next != nullptr && cnt < k) {
                ListNode *temp = next->next;
                next->next = prev;
                prev = next;
                next = temp;
                cnt++;
            }

            if (cnt < k) {
                head->next = nullptr;
                dummyNode->next = reverseKGroup(prev, cnt);
                return dummyNode->next;
            } else {
                dummyNode->next->next = reverseKGroup(next, k);
            }
            return prev;
    }
};

