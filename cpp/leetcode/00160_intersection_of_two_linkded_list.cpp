//我的解法
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1 = headA;
        ListNode *l2 = headB;

        if (l1 == nullptr || l2 == nullptr) {
            return nullptr;
        }

        while(l1 || l2) {
            if (l1 == l2) {
                return l1;
            }

            l1 = l1->next;
            l2 = l2->next;

            if (l1 == nullptr && l2 != nullptr) {
                l1 = headB;
            }

            if (l2 == nullptr && l1 != nullptr) {
                l2 = headA;
            }
        }
        return nullptr;
    }
};

//官方的双指针， 更加简洁
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};
