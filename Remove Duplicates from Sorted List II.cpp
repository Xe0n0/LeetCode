//1. consider terminate and return when found a bound condition.
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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return head;
        
        ListNode *p = head;
        ListNode *b = new ListNode(-1);
        b->next = head;
        ListNode *preprev = b;
        ListNode *prev = p;
        p = p->next;
        
        while (p) {
            if (p->val == prev->val) {
                while (p && p->val == prev->val) {
                
                    p = p->next;         
                }
                preprev->next = p;
                
                if (p == NULL) return b->next;
                
                prev = p;
                p = p->next;
            }
                
            else {
                preprev = prev;
                prev = p;
                p = p->next;
                
            }
            
        }
        
        return b->next;
    }
};