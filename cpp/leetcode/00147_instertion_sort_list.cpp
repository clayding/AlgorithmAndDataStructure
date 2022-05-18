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
// 按照官方说的解法做的
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // 1. 首先判断给定的链表是否为空，若为空，则不需要进行排序，直接返回。
        if （head == nullptr） {
            return head;
        }

        // 2. 链表初始化操作
        ListNode* dummyNode = new ListNode(0); // 引入哑节点
        dummyNode->next = head;                // 目的是在head之前插入节点
        ListNode* lastSorted = head;           // 维护lastSorted为链表已经排好序的最后一个节点并初始化
        ListNode* curr = lastSorted->next;     // 维护curr 为待插入的元素并初始化

        while(curr != nullptr) {               // 说明curr应该位于lastSorted之后
            if (lastSorted->val <= curr->val) {// 将lastSorted后移一位,curr变成新的lastSorted
                lastSorted = lastSorted->next; // 否则,从链表头结点开始向后遍历链表中的节点
            } else {                           
                ListNode* prev = dummyNode;    // 从链表头开始遍历 prev是插入节点curr位置的前一个节点
                while(prev->next->val <= curr->val) { // 循环退出的条件是找到curr应该插入的位置
                    prev = prev->next;
                }
                // 以下三行是为了完成对curr的插入（配合题解动图可以直观看出）
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr; // 此时 curr 为下一个待插入的元素
            }

            curr = lastSorted->next;
        }
        // 返回排好序的链表
        return dummyNode->next;
    }
};