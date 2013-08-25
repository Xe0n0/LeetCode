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
    int sumWithRoot(int pre, TreeNode *root){
            
        if (root->left == NULL && root->right == NULL) {
            return pre * 10 + root->val;
        }
        
        int r = 0;

        if (root->left)
            r += sumWithRoot(pre * 10 + root->val, root->left);
        
        if (root->right)
            r += sumWithRoot(pre * 10 + root->val, root->right);
            
        return r;
    }
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return 0;
        
        return sumWithRoot(0, root);
    }
};