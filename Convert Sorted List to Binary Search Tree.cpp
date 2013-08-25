/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *sortedArrayToBSTAtRange(vector<ListNode *> &num, int a, int b) {
        int n = b - a;
        
        if (n <= 0) return NULL;
        
        TreeNode *head = new TreeNode(num[a + n/2]->val);
        
        head->left = sortedArrayToBSTAtRange(num, a, a + n/2);
        
        head->right = sortedArrayToBSTAtRange(num, a + n/2 + 1, b);
    }
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<ListNode *> vl;
        
        while (head != NULL) {
            vl.push_back(head);
            head = head->next;
        }
        
        return sortedArrayToBSTAtRange(vl, 0, vl.size());
    }
};