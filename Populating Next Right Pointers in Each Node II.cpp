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
        
        while (node->left || node->right) {
            if (node->left) {
                node->left->next = node->right;
                
                if (node->right)
                    node->right->next = node;
                else
                    node->left->next = node;
                    
                node = node->left; 
            }
            else {
                node->right->next = node;
                node = node->right;
            }
        }
        
            
        if (node == root) return;

        TreeLinkNode *prev = node;
        TreeLinkNode *lefts = NULL;

        node = node->next;
   
        
        while (node != NULL) {
            
            //travel up along right next
            while (node != NULL &&
                (node->right == prev || node->left == prev)) {
                prev->next = lefts;
                lefts = prev;
                prev = node;
                node = node->next;
            }
            
            if (node == NULL) break;
                        
            //when prev is left child of node
            while (node->left||node->right) {
                if (node->left) {
                    node->left->next = node->right;
                
                    if (node->right)
                        node->right->next = node;
                    else
                        node->left->next = node;
                    
                    node = node->left; 
                }
                else {
                    node->right->next = node;
                    node = node->right;
                }
                if (lefts) {
                    TreeLinkNode *t = lefts;
                    lefts = lefts->next;
                    t->next = node;
                }
            }
            
            
            prev = node;
            
            node = node->next;
            
        }
        
        //node = root;
        
        //while (node) {
          //  node->next = NULL;
            //if (node->right)
              //  node = node->right;
            //else
              //  node = node->left;
        //}
        while (lefts) {
            TreeLinkNode *t = lefts;
            lefts = lefts->next;
            t->next = NULL;
        }
        root->next = NULL;
    }
};