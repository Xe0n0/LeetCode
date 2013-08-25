//1. be carefull after change list with swap
//2. reset head for return afer modify
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
    ListNode* reverseK(ListNode **begin, ListNode **end){
        stack<ListNode *> s;
        
        ListNode *p = *begin;
        ListNode *next = (*end)->next;
        
        while (p != (*end)->next) {
            s.push(p);
            p = p->next;
        }
        
        ListNode *head = new ListNode(-1);
        p = head;
        
        while (!s.empty()) {
            p -> next = s.top();
            p = p->next;
            s.pop();
        }
        
        p->next = next;
        
        ListNode *t = *begin;
        *begin = *end;
        *end = t;
        
        return head->next;
    }
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (k <= 1 || head == NULL) return head;
        
        int count = k;
        
        ListNode * begin = head;
        ListNode * end = head;
        
        while (--count && end != NULL) {
            end = end->next;
        }
        
        ListNode *t;
        if (end)
        {
            reverseK(&begin, &end);
            head = begin;
        }
            
        
        while (end != NULL) {
            
            count = k;
            
            ListNode *prev = end;

            while (count-- && end != NULL) {
                begin = begin->next;
                end = end->next;
            }
            
            if (end)
            {
                prev->next = reverseK(&begin, &end);

            }
        }
        
        return head;
        
    }
};