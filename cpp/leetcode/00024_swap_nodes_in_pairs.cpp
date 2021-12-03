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
    ListNode* swapPairs(ListNode* head) {
        // three pointers
        ListNode *prev = NULL;
        ListNode *curr = NULL;
        ListNode *p = NULL;

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        prev = head; // 1
        curr = head->next; //2

        if(curr != nullptr){
            ListNode *tmp = curr->next; // 3
            curr->next = prev; //2->next = 1
            p = prev; // p = 1
            prev = curr; // prev = 2
            curr = tmp; // curr  = 3
            p->next = swapPairs(curr); // 1->next = 4
        }

        return prev; //return 2
    }
};


//改进版
class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        // three pointers
        ListNode *prev = NULL;
        ListNode *curr = NULL;

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        prev = head; // 1
        curr = head->next; //2

        if(curr != nullptr){
            prev->next = swapPairs(curr->next); // 1->next = 4
            curr->next = prev; //2->next = 1
        }

        return curr; //return 2
    }
};

//再改进版
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        curr = head->next; //2

        if(curr != nullptr){
            head->next = swapPairs(curr->next); // 1->next = 4
            curr->next = head; //2->next = 1
        }

        return curr; //return 2
    }
};

// 上面都是递归，现在写一个迭代
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummyNode = new ListNode(0);
        ListNode *tmp = NULL;
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        dummyNode->next = head;
        tmp = dummyNode;

        while (tmp->next != nullptr && tmp->next->next != nullptr) {
            ListNode *node1 = tmp->next; //head
            ListNode *node2 = tmp->next->next; //head->next
            tmp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            tmp = node1;
        }

        return dummyNode->next; //return 2
    }
};
