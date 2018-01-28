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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode* one = head;
        ListNode* two = head;
        while (two->next && two->next->next){
            one = one->next;
            two = two->next->next;
        }
        one->next = reverse(one->next);
        one = one->next;
        while (one) {
            if (one->val != head->val) return false;
            one = one->next;
            head = head->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head) {
        if (head == NULL) return head;
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* r;
        head->next = NULL;
        while (q) {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }
};