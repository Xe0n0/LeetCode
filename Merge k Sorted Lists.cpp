/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *mergeTwo(ListNode *a, ListNode *b) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        
        while (a && b) {
            if (a -> val < b-> val) {
                p->next = a;
                a = a->next;
                p = p->next;
            }
            else {
                p->next = b;
                b = b->next;
                p = p->next;
            }
        }
        
        while (a) {
            p->next = a;
            a = a->next;
            p = p->next;
        }
        while (b) {
            p->next = b;
            b = b->next;
            p = p->next;
        }
        
        return head->next;
    }
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<ListNode *> q;
        
        for (int i = 0; i < lists.size(); i++) {
            q.push(lists[i]);
        }
        
        while(q.size() > 1) {
            ListNode *a = q.front();
            q.pop();
            ListNode *b = q.front();
            q.pop();
            
            q.push(mergeTwo(a, b));
        }
        
        if (q.size()) return q.front();
        
        return NULL;
    }
};