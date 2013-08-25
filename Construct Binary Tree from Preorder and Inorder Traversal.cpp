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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTreeAtRange(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
private:
    TreeNode *buildTreeAtRange(vector<int> &preorder, vector<int> &inorder,
        int a, int b, int c, int d) {
        
        if (a >= b || c >= d) return NULL;
        
        int val_r = preorder[a];
        
        vector<int>::iterator pit = find(inorder.begin() + c, inorder.begin() + d, val_r);
        
        if (pit != inorder.begin() + d) {
            
            int pivot = pit - inorder.begin() - c;
            
            TreeNode *root = new TreeNode(val_r);
            
            root->left = buildTreeAtRange(preorder, inorder, a + 1, a + 1 + pivot, c, c + pivot);
            
            root->right = buildTreeAtRange(preorder, inorder, a + 1 + pivot, b, c + pivot + 1, d);
            
            return root;
            
        }
        
        return NULL;
        
    }
};