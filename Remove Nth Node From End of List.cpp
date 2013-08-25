//1. remove head, tail
//2. remove the only one
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL || n == 0) return head;
        
        ListNode * p = head;
        ListNode * h = head;
        
        while(--n && p != NULL) {
            p = p->next;
        }
        
        ListNode * prev = h;
        
        while (p->next != NULL) {
            p = p->next;
            prev = h;
            h = h->next;
        }
        
        if (h == head) return head->next;
        
        prev->next = h->next;
        
        return head;
    }
};