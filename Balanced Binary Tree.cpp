//1. don't forget to increase depth
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
    bool isBalancedWithDepth(TreeNode *root, int& depth) {
        if (root == NULL) {
            depth = 0;
            return true;
        }
        if (root->left == NULL && root->right == NULL) {
            depth = 1;
            return true;
        }
        
        depth = 0;
        int dl = 0;
        int dr = 0;
        
        if (root->left) {
            if (!isBalancedWithDepth(root->left, dl))
                return false;
            
            depth = max(dl+1, depth);
        }
        
        if (root->right) {
            if (!isBalancedWithDepth(root->right, dr))
                return false;
                
            depth = max(dr+1, depth);
        }
        
        if (abs(dl - dr) > 1) return false;
        
        return true;
    }
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int t;
        return isBalancedWithDepth(root, t);
    }
};