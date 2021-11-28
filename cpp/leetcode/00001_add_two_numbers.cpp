#ifdef ADD_TWO_NUM
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
方案 1:
class Solution {
private:
    int sum = 0;
    ListNode *next = nullptr;
    ListNode *header = nullptr;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l1t = l1;
        ListNode *l2t = l2;
        if (l1t != nullptr || l2t != nullptr || sum != 0) {
            ListNode* result = new ListNode;
            if (l1t == nullptr) {
                l1t = new ListNode;
            }
            if (l2t == nullptr) {
                l2t = new ListNode;
            }

            sum += l1t->val + l2t->val;
            result->val = sum%10;
            sum = sum/10;

            if (header == nullptr) {
                header = new ListNode;
                header->next = result;
                next = result;
            } else {
                next->next = result;
                next = result;
            }

            addTwoNumbers(l1t->next, l2t->next);
        }

        return header->next;
    }
};

// 执行用时：40 ms , 在所有 C++ 提交中击败了 17.66% 的用户
// 内存消耗：69.8 MB, 在所有 C++ 提交中击败了 5.18% 的用户
// 通过测试用例：1568 / 1568

//--------------------------------------------------------------------------------
// 方案 2:
class Solution {
private:
    int sum = 0;
    ListNode *next = nullptr;
    ListNode *header = nullptr;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l1t = l1;
        ListNode *l2t = l2;
        ListNode *l1n = nullptr;
        ListNode *l2n = nullptr;
        if (l1t != nullptr || l2t != nullptr || sum != 0) {
            ListNode* result = nullptr;
            if (l1t != nullptr) {
                sum += l1t->val;
                l1n = l1t->next;
                result = l1t;
            }
            if (l2t != nullptr) {
                sum += l2t->val;
                l2n = l2t->next;
                result = l2t;
            }

            if (result == nullptr) {
                result = new ListNode();
            }

            result->val = sum%10;
            sum = sum/10;

            if (header == nullptr) {
                header = result;
                next = result;
            } else {
                next->next = result;
                next = result;
            }

            addTwoNumbers(l1n, l2n);
        }

        return header;
    }
};

// 执行用时：28 ms, 在所有 C++ 提交中击败了68.32%的用户
// 内存消耗：68.9 MB, 在所有 C++ 提交中击败了98.59%的用户
// 通过测试用例：1568 / 1568
// --------------------------------------------------------------------------------

// 方案 3:
class Solution {
private:
    int sum = 0;
    ListNode *next = nullptr;
    ListNode *header = nullptr;
    ListNode *l1t = nullptr;
    ListNode *l2t = nullptr;
    ListNode *l1n = nullptr;
    ListNode *l2n = nullptr;
    ListNode *result = nullptr;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1t = l1;
        l2t = l2;
        result = nullptr;
        if (l1t != nullptr || l2t != nullptr || sum != 0) {
            if (l1t != nullptr) {
                sum += l1t->val;
                l1n = l1t->next;
                result = l1t;
            }
            if (l2t != nullptr) {
                sum += l2t->val;
                l2n = l2t->next;
                result = l2t;
            }

            if (result == nullptr) {
                result = new ListNode();
            }

            result->val = sum%10;
            sum = sum/10;

            if (header == nullptr) {
                header = result;
                next = result;
            } else {
                next->next = result;
                next = result;
            }

            addTwoNumbers(l1n, l2n);
        }

        return header;
    }
};

// 执行用时：20 ms, 在所有 C++ 提交中击败了93.11%的用户
// 内存消耗：68.9 MB, 在所有 C++ 提交中击败了97.29%的用户
// 通过测试用例：1568 / 1568

// --------------------------------------------------------------------------------

// 方案 4:
class Solution {
private:
    int sum = 0;
    ListNode *next = nullptr;
    ListNode *header = nullptr;
    ListNode *l1t = nullptr;
    ListNode *l2t = nullptr;
    ListNode *result = nullptr;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1t = l1;
        l2t = l2;
        while (l1t != nullptr || l2t != nullptr || sum != 0) {
            result = nullptr;
            if (l1t != nullptr) {
                result = l1t;
                sum += l1t->val;
                l1t = l1t->next;
            }
            if (l2t != nullptr) {
                result = l2t;
                sum += l2t->val;
                l2t = l2t->next;
            }

            if (result == nullptr) {
                result = new ListNode();
            }

            result->val = sum%10;
            sum = sum/10;

            if (header == nullptr) {
                header = result;
                next = result;
            } else {
                next->next = result;
                next = result;
            }
        }

        return header;
    }
};

// 执行用时：24 ms, 在所有 C++ 提交中击败了83.51%的用户
// 内存消耗：68.8 MB, 在所有 C++ 提交中击败了99.11%的用户
// 通过测试用例：1568 / 1568

// --------------------------------------------------------------------------------

// 方案 5:
class Solution {
private:
    int sum = 0;
    ListNode *next = nullptr;
    ListNode *header = nullptr;
    ListNode *result = nullptr;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr) {
                result = l1;
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                result = l2;
                sum += l2->val;
                l2 = l2->next;
            }

            result->val = sum%10;
            sum = sum/10;

            if (header == nullptr) {
                header = result;
                next = result;
            } else {
                next->next = result;
                next = result;
            }
        }

        if (sum != 0) {
            result = new ListNode(sum);
            next->next = result;
        }

        return header;
    }
};
#endif //ADD_TWO_NUM
