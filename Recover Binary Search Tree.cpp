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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *pre{NULL}, *parent{NULL}, *p;
        
        p = root;
        
        TreeNode *f1, *f2;
        bool found = false;
        
        while (p) {
            
            if (p->left) {
                pre = p->left;
                
                while (pre->right && pre->right != p)
                    pre = pre->right;
                
                if (pre->right == NULL) {
                    pre->right = p;
                    p = p->left;
                    continue;
                }
                else {
                    pre->right = NULL;
                    if (parent && parent->val > p->val) {
                        if (!found)
                            f1 = parent;
                        
                        f2 = p;
                        found = true;
                    }
                    
                    parent = p;
                    p = p->right;
                    
                    
                }
            }
            else {
                
                if (parent && parent->val > p->val) {
                    if (!found)
                        f1 = parent;
                    f2 = p;
                    found = true;
                }
                parent = p;
                p = p->right;
            }
        }
        
        swap(f1->val, f2->val);
    }
};