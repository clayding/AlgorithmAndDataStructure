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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> hashset;
        ListNode *node = head;

        auto it = hashset.find(node); 
        while(node != nullptr) {
            if (hashset.count(node)) {
                return node;
            }
            hashset.insert(node);
            node = node->next;
        }
        return nullptr;

    }
};

// 双指针
// fast 走过的路程 = a + n(b+c) +b
// slow 走过的路程 = a + b
//那么 a + n(b+c) +b = 2(a + b) ; 换算为
// (n-1)(b+c) + c  = a
// 有了 a=c+(n-1)(b+c)a=c+(n−1)(b+c) 的等量关系，我们会发现：从相遇点到入环点的距离加上 n-1
// 圈的环长，恰好等于从链表头部到入环点的距离。

// 因此，当发现 slow 与 fast 相遇时，我们再额外使用一个指针 ptr。起始，它指向链表头部；
// 随后，它和 slow 每次向后移动一个位置。最终，它们会在入环点相遇。

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                ListNode *p = head;
                while (p != slow) {
                    p = p->next;
                    slow = slow->next;
                }

                return p;
            }
        }
        return nullptr;
    }
};
