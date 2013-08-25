//1. what if k >= number of nodes?
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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (head == NULL) return NULL;
        if (k <= 0) return head;
        
        ListNode *p1 = head;
        ListNode *p2 = head;
        ListNode *prev = NULL;
        
        while (k--) {
            if (p2->next == NULL) {p2 = head;}
            else
                p2 = p2->next;
        }
        
        if (head == p2) return head;
        
        while (p2->next) {
            p2 = p2->next;
            prev = p1;
            p1 = p1->next;
        }
                
        p2->next = head;
        head = p1->next;

        p1->next = NULL;
        
        return head;
    }
};