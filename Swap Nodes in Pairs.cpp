//rev.2 revised, careful multi pointer swap or forward position
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *edge = new ListNode(0);
        
        edge->next = head;
        
        ListNode *p = edge->next;
        ListNode *p2 = edge->next->next;
        ListNode *pre = edge;
        
        while (p2) {
            
            pre->next = p2;
            p->next = p2->next;
            p2->next = p;
            
            if (p->next == NULL) break;
            
            p = p->next;
            p2 = p->next;
            pre = pre->next->next;
        }
        
        return edge->next;
    }
};
//rev.1
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
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return reverseKGroup(head, 2);
    }
};