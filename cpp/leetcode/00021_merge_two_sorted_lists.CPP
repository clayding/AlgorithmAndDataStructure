
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
//递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = nullptr;

        if (list1 && list2) {
            if (list1->val <= list2->val) {
               list1->next = mergeTwoLists(list1->next, list2);
               head = list1;
            } else { //list1->val > list2->val
               list2->next = mergeTwoLists(list1, list2->next);
               head = list2;
            }
        }

        //only one of list1 and list2 is nullptr
        if(list1 == nullptr) {
            return list2;
        } 
        if (list2 == nullptr){
            return list1;
        }

        return head;
    }
};

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummyNode = new ListNode(0);
        ListNode *prev = dummyNode;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                prev->next = list1;
                list1 = list1->next;
            } else { //list1->val > list2->val
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }

        //only one of list1 and list2 is nullptr
        prev->next = list1 == nullptr?list2:list1;

        return dummyNode->next;
    }
};

//迭代，第二遍
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = nullptr;

        if (list1 && list2) {
            if (list1->val <= list2->val) {
               list1->next = mergeTwoLists(list1->next, list2);
               head = list1;
            } else { //list1->val > list2->val
               list2->next = mergeTwoLists(list1, list2->next);
               head = list2;
            }
        }

        //only one of list1 and list2 is nullptr
        if(list1 == nullptr) {
            return list2;
        } 
        if (list2 == nullptr){
            return list1;
        }

        return head;
    }
};
