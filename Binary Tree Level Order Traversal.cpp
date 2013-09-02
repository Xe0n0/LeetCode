//rev.2 non-recursive
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode *> q;
        
        vector<vector<int> > r;
        
        q.push_back(root);
        
        int idx = 0;
        int end = 0;
        
        while (q.size() > idx) {
            
            end = q.size();
            
            vector<int> temp;
            
            for (int i = idx; i < end; i++) {
                
                TreeNode *p = q[i];
                if (p) {
                    
                    temp.push_back(p->val);
                    q.push_back(p->left);
                    q.push_back(p->right);
                }
            }
            if (temp.size() > 0)
                r.push_back(temp);
            idx = end;
        }
        reverse(r.begin(), r.end());
        return r;
    }
};
//rev.1 recursive
class Solution {
public:
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