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
    ListNode* reverseList(ListNode* head) {
        //使用3个指针遍历单链表，逐个链接点进行反转，使用p和q两个指针配合工作，
        //使得两个节点间的指向反向，同时用r记录剩下的链表。
        if (head == NULL) return head;
        ListNode* p = head;
        ListNode* q = head->next;
        head->next = NULL;
        ListNode* r;
        while (q) {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }
};