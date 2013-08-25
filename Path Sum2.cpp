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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > vs;
        
        if (!root) return vs;
        
        if (root->left == NULL & root->right == NULL
            && sum == root->val) {
                vector<int> temp;
                temp.push_back(sum);
                vs.push_back(temp);
                
                return vs;
            }
            
        if (root->left) {
            vector<vector<int> > vs_t = pathSum(root->left, sum - root->val);
            
            for_each(vs_t.begin(), vs_t.end(), [&vs, root](vector<int> &v) {
                v.insert(v.begin(), root->val);
                vs.push_back(v);
            });
        }
        
        if (root->right) {
            vector<vector<int> > vs_t = pathSum(root->right, sum - root->val);
            
            for_each(vs_t.begin(), vs_t.end(), [&vs, root](vector<int> &v) {
                v.insert(v.begin(), root->val);
                vs.push_back(v);
            });
        }
                
        return vs;
    }
};