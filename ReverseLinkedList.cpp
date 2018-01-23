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
        //ʹ��3��ָ�����������������ӵ���з�ת��ʹ��p��q����ָ����Ϲ�����
        //ʹ�������ڵ���ָ����ͬʱ��r��¼ʣ�µ�����
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