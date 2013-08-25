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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *prev = NULL;
        ListNode *ph = NULL;
        ListNode *pm = NULL;
        ListNode *pn = NULL;
        ListNode *pnext = NULL;
        ListNode *p = head;
        
        int c = 1;
        
        while (p) {
            
            if (c == m ) {
                pm = p;
            }
            
            if (c == m - 1) {
                ph = p;
            }
            
            if (c == n) {
                pn = p;
                pnext = p->next;
                p->next = prev;
                if (ph) {
                    ph->next = p;
                    pm->next = pnext;
                    return head;
                }
                else {
                    pm->next = pnext;
                    return p;
                }
            }
            
            c++;
            ListNode *t = prev;
            prev = p;
            p = p->next;
            
            if (c > m + 1)
                prev->next = t;
        }
    }
};