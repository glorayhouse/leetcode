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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cur1 = headA;
        ListNode *cur2 = headB;
        while (cur1 != cur2) {
            //网上的解法，不是很理解，感觉链表环、交点的解法都是一个圈，要么是八字圈，最后都是个封闭的图形，先mark
            cur1 = cur1 ? cur1->next : headB;
            cur2 = cur2 ? cur2->next : headA;
        }
        return cur1;
    }
};