/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return;
        
        TreeLinkNode *node = root;
        
        while (node->left) {
            node->left->next = node->right;
            node->right->next = node;
            node = node->left;
        }
        
            
        if (node == root) return;

        TreeLinkNode *prev = node;

        node = node->next;
        
        while (node != root) {
            
            //travel up along right next
            while (node != NULL && node->right == prev) {
                prev = node;
                node = node->next;
            }
            
            if (node == NULL) break;
            
            TreeLinkNode *left = prev;
            
            //when prev is left child of node
            while (node->left) {
                node->left->next = node->right;
                node->right->next = node;
                node = node->left;
                left = left->right;
                left->next = node;
            }
            
            
            prev = node;
            
            node = node->next;
            
        }
        
        node = root;
        
        while (node) {
            node->next = NULL;
            node = node->right;
        }
    }
};