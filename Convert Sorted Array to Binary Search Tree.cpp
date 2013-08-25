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
    TreeNode *sortedArrayToBSTAtRange(vector<int> &num, int a, int b) {
        int n = b - a;
        
        if (n <= 0) return NULL;
        
        TreeNode *head = new TreeNode(num[a + n/2]);
        
        head->left = sortedArrayToBSTAtRange(num, a, a + n/2);
        
        head->right = sortedArrayToBSTAtRange(num, a + n/2 + 1, b);
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return sortedArrayToBSTAtRange(num, 0, num.size());
    }
};