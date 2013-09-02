//rev.2 using heap(priority_queue)
class compare {
public:
    bool operator()(ListNode *a, ListNode *b) {
        
        return a->val > b->val;
    }
};
class Solution {
public:
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        
        priority_queue<ListNode*, vector<ListNode*>, compare > q;
        
        for_each(lists.begin(), lists.end(), [&q](ListNode *a){
            if (a) 
                q.push(a);
        });
        
        while (!q.empty()) {
            
            p->next = q.top();
            q.pop();
            p = p->next;
            
            if (p->next) {
                q.push(p->next);
            }

        }
        
        return head->next;
        
    }
};
//rev.1
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