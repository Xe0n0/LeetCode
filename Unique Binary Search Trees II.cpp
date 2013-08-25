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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return generateTreesRecursively(1, n);
    }
private:
    vector<TreeNode *> generateTreesRecursively(
        int start, int end) {
            
            vector<TreeNode *> r;
            
            if (start > end) {
                r.push_back(NULL);
                return r;
            }
            
            if (start == end) {
                TreeNode *p = new TreeNode(start);
                r.push_back(p);
                return r;
            }
            
            for (int i = start; i <= end; i++) {
                
                vector<TreeNode *> left_trees = generateTreesRecursively(start, i - 1);
                vector<TreeNode *> right_trees = generateTreesRecursively(i + 1, end);
                
                for (int j = 0; j < left_trees.size(); j++) {
                    
                    for (int k = 0; k < right_trees.size(); k++) {
                        
                        TreeNode *head = new TreeNode(i);
                        head->left = left_trees[j];
                        head->right = right_trees[k];
                        r.push_back(head);
                    }
                }
            }
            
            return r;
            
        }
};