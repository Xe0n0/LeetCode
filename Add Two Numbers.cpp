//mistake:
//1. forget increase point p
//2. should subtract 10 only when larger than 10
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int carry = 0;
        
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        
        ListNode *head = new ListNode(0);
        ListNode *c = head;
        
        while(p1 && p2) {
            
            c->next = new ListNode(0);
            c = c->next;
            
            c->val = p1->val + p2->val + carry;
            
            carry = c->val / 10;
            c->val %= 10;
            
            
            
            p1 = p1->next;
            p2 = p2->next;
        }
        
        while (p1) {
            c->next = new ListNode(p1->val + carry);
            c = c->next;
            
            carry = c->val / 10;
            c->val %= 10;
            
            p1 = p1->next;
        }
        
        while (p2) {
            c->next = new ListNode(p2->val + carry);
            c = c->next;
            carry = c->val / 10;
            c->val %= 10;
            p2 = p2->next;
        }
        
        if (carry) {
             c->next = new ListNode(carry);
        }
        
        return head->next;
    }
};