//1. forgot to flip flag
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return zigzagLevelOrderWithDepth(root, 0);
    }
private:
    vector<vector<int> > zigzagLevelOrderWithDepth(TreeNode *root, int depth) {
        
        vector<vector<int> > r;
        
        if (root == NULL) {
            return r;
        }
        
        r.push_back(vector<int>(1, root->val));
        
        vector<vector<int> > tl = zigzagLevelOrderWithDepth(root->left, depth + 1);
        vector<vector<int> > tr = zigzagLevelOrderWithDepth(root->right, depth + 1);
        
        bool flag = true;
        
        if (depth % 2) {
            flag = false;
        }
        
        int i{0}, j{0};
        
        while (i < tl.size() && j < tr.size()) {
            
            vector<int> temp1 = tl[i++];
            vector<int> temp2 = tr[j++];
            
            if (!flag) {
                temp1.resize(temp1.size() + temp2.size());
                copy(temp2.begin(), temp2.end(), temp1.end() - temp2.size());
                r.push_back(temp1);
            }
            else {
                temp2.resize(temp1.size() + temp2.size());
                copy(temp1.begin(), temp1.end(), temp2.end() - temp1.size());
                r.push_back(temp2);
            }
            
            flag = !flag;
            
        }
        
        while (i < tl.size()) {
            r.push_back(tl[i++]);
        }
        
        while (j < tr.size()) {
            r.push_back(tr[j++]);
        }
        
        return r;
        
    }
};