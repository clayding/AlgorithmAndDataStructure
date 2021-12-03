//双指针
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *first = head;
        ListNode *second = head;
        int pos = -1;

        while (first != nullptr && second != nullptr && second->next != nullptr) {
            first = first->next;
            second = second->next->next;

            if (first == second) {
                return true;
            }
        }

        return false;
    }
};

// hashmap
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> hashset;
        ListNode *node = head;

        auto it = hashset.find(node); 
        while(node != nullptr) {
            if (hashset.count(node)) {
                return true;
            }
            hashset.insert(node);
            node = node->next;
        }
        return false;

    }
};
