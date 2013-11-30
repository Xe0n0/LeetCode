//1. to form max path, we need max_sum of subtrees, and max_path of subtrees, O(n)
class Solution {
private:
    int maxPathAndSum(TreeNode *root, int &path) {
        if (root == NULL) {
            path = 0;
            return 0;
        }
        
        if (root->left == NULL && root->right == NULL) {
            path = root->val;
            return root->val;
        }
        
        int pathl{0}, pathr{0};
        
        int suml{INT_MIN}, sumr{INT_MIN};
        
        if (root->left) {
            suml = maxPathAndSum(root->left, pathl);
        }
        
        if (root->right) {
            sumr = maxPathAndSum(root->right, pathr);
        }
        
        path = max(pathl + root->val, pathr + root->val);
        path = max(path, root->val);
        
        int sum = root->val;
        
        if (pathl > 0) {
            sum += pathl;
        }
        if (pathr > 0 ) {
            sum += pathr;
        }
        
        sum = max(sum, suml);
        sum = max(sum, sumr);
        
        return sum;
    }
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int t;
        return maxPathAndSum(root, t);
    }
};