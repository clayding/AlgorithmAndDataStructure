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

//官方的解答:
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; // 注意这里直接设置 prev为nullptr
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};


// 题目是删除中间节点， 如果节点是偶数 删除中间的2个节点 如果中间节点是奇数 删除中间一个节点
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
        if (head == nullptr)
            return head;
        rmMidNodes(head);
        return reverseLists(head);
    }

    void rmMidNodes(ListNode* head) {
        ListNode* fst = head;
        ListNode* slw = head;
        ListNode* pre = head;

        while(fst != nullptr && fst->next != nullptr) {
            fst = fst->next->next;
            if(fst == nullptr) {
                break;
            }
            pre = slw;
            slw = slw->next;
        }

        if (fst == nullptr) {
            pre->next = slw->next->next;
        } else {
            pre->next = slw->next;
        }
    }

    ListNode* reverseLists(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* prev = head;

        while(curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head->next = nullptr;
        return prev;
    }
};