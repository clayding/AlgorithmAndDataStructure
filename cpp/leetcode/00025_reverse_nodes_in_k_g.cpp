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

//第3次做的答案
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
        if (head == nullptr) {
            return head;
        }

        ListNode *tmp = head;
        int count = 0;
        while (tmp) {
            tmp = tmp->next;
            count++;
        }

        if (count < k) {
            return head;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        count = k-1;
        while(curr != nullptr && count-- > 0 ) {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        head->next = reverseKGroup(curr, k);
        return prev;
    }
};

