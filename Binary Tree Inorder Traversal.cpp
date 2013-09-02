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
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> r;
        
        stack<TreeNode *> s;
        
        TreeNode *p = root;
        
        while (p || !s.empty()) {
            
            if (p) {
                
                s.push(p);
                p = p->left;
            }
            else {
                
                p = s.top();
                s.pop();
                
                r.push_back(p->val);
                p = p->right;
            }
        }
        
        return r;
    }
};