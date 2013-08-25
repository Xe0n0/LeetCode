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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL || root->left == NULL && root->right == NULL) {
            return;
        }
        
        TreeNode *p = root->left;
        
        if (p) {
            
            flatten(p);
                        
            while (p->right != NULL) {
                p = p->right;
            }
        }
        
        if (root->right) {
            flatten(root->right);
        }
        
        if (p) {
            p->right = root->right;
            root->right = root->left;
            root->left = NULL;

        }
        
    }
};