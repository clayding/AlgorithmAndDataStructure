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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return;
        }

        ListNode *mid = midNode(head);
        ListNode *tail = reverseFromMid(mid);

        ListNode *hnod = head;
        ListNode *tnod = tail;

        while (hnod != nullptr && tnod != nullptr) {
            cout << "hnod:" << hnod->val << " tnod:" << tnod->val << endl;
            ListNode *nod1 = hnod->next; //3
            hnod->next = tnod; //3
            ListNode *nod2 = tnod->next; //2
            tnod->next = nod1; // 2

            hnod = nod1; //2
            tnod = nod2; //3

            if (hnod == tnod || hnod->next == tnod) {
                break;
            }
        }
    }

    ListNode* midNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;

        ListNode *fst = dummyNode;
        ListNode *slw = dummyNode;

        while (fst) {
            if (fst->next)
                fst = fst->next->next;
            else
                fst = fst->next;
            slw = slw->next;
        }

        //find middle node
        return slw;
    }

    ListNode* reverseFromMid(ListNode* mid) {
        if (mid == nullptr && mid->next == nullptr) {
            return mid;
        }

        ListNode *prev = mid;
        ListNode *curr = mid->next;

        while (curr) {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        mid->next = nullptr;
    
        return prev; //return tail node (last node of original list)
    }
};


//官方解法
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while (l1 != nullptr && l2 != nullptr) {
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
    }
};
