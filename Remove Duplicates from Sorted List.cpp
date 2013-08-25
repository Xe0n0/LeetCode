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
        ListNode *prev = p;
        
        p = p->next;
        
        while (p) {
            
            if (p->val == prev->val) {
                
                prev->next = p->next;
                
            }
            else
                prev = p;
                
            p = p->next;
            
        }
        
        return head;
    }
};