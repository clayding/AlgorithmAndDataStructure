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
// 下面这个解法有问题， 改进详见改进版
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // find middle node
        ListNode* mid = midNode(head);

        //reverse list
        ListNode* tail = reverseList(mid);
        ListNode* slist = head;

        while (tail->val == slist->val) {
            //printf(" %d-%d ", tail->val, slist->val);
            //printf(" %p-%p ", tail, slist->next);
            if (tail == slist->next) {
                return true;
            }
            tail = tail->next;
            slist = slist->next;
        }

        return false;
    }

    ListNode* midNode(ListNode* head) {
        ListNode* fst = head;
        ListNode* slw = head;

        while(fst && fst->next) {
            fst = fst->next->next;
            if (fst == nullptr) {
                break;
            }
            slw = slw->next;
        }
        return slw;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = prev->next;

        while(curr != nullptr) {
            ListNode* temp = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // head=>next = nullptr;
        return prev;
    }
};

// 改进版
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // find middle node
        ListNode* mid = midNode(head);

        //reverse list
        ListNode* tail = reverseList(mid);
        ListNode* slist = head;

        while (tail != nullptr) {  // 不判断2指针的地址相等， 不可靠
            if (tail->val != slist->val) {
                return false;
            }
            tail = tail->next;
            slist = slist->next;
        }

        return true;
    }

    ListNode* midNode(ListNode* head) {
        ListNode* fst = head;
        ListNode* slw = head;

        while(fst && fst->next) {
            fst = fst->next->next;
            if (fst == nullptr) {
                break;
            }
            slw = slw->next;
        }
        return slw;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; // 反转以后 原来的头节点指向空
        ListNode* curr = head->next;

        while(curr != nullptr) {
            ListNode* temp = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        //head->next = nullptr;
        return prev;
    }
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }

        // 找到前半部分链表的尾节点并反转后半部分链表
        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

        // 判断是否回文
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool result = true;
        while (result && p2 != nullptr) {
            if (p1->val != p2->val) {
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }        

        // 还原链表并返回结果
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
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

    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};