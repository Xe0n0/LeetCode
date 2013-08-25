//1. it's easier to do up to bottom, can you realize it in a short time?
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > r = levelOrder(root);
        reverse(r.begin(), r.end());
        
        return r;
    }
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > r;
        
        if (root == NULL) return r;
        
        r.push_back(vector<int>(1, root->val));        
        
        vector<vector<int> > rl = levelOrder(root->left);
        
        vector<vector<int> > rr = levelOrder(root->right);
        
        int i = 0;
        
        for (i = 0; i < rl.size() && i < rr.size(); i++) {
            vector<int> &t = rl[i];
            vector<int> &t2 = rr[i];
            
            t.resize(t.size() + t2.size());
            copy(t2.begin(), t2.end(), t.end()-t2.size());
            r.push_back(t);
        }
        
        while (i < rl.size()) {
            r.push_back(rl[i]);
            i++;
        }
        
        while (i < rr.size()) {
            r.push_back(rr[i]);
            i++;
        }
        
        return r;
    }
};