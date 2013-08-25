//1. when use index split, careful of convert absolute index to relative ones
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (inorder.size() <= 0 || postorder.size() <= 0) return NULL;
        
        return buildTreeAtRange(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
    
private:
    TreeNode *buildTreeAtRange(vector<int> &inorder, vector<int> &postorder,
    int a, int b, int c, int d){
        if (a >= b || c >= d) return NULL;
        
        int val_r = postorder[d-1];
        vector<int>::iterator lit = find(inorder.begin() + a, inorder.begin() + b, val_r);
        
        int pivot = lit - inorder.begin() - a;
        TreeNode *root = new TreeNode(val_r);
        root->left = buildTreeAtRange(inorder, postorder,
            a, a + pivot, c, c + pivot);
        root->right = buildTreeAtRange(inorder, postorder,
            a + pivot + 1, b, c + pivot, d - 1);
            
        return root;
    };
};