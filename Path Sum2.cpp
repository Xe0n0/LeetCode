//1. non-recursive
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > vs;
        
        if (!root) return vs;
        
        TreeNode *p = root;
        
        stack<TreeNode*> s;
        unordered_set<TreeNode*> v;
        vector<int> path;
        
        int cur = 0;
        
        while (p || !s.empty()) {
            
            if (p) {
                
                s.push(p);
                path.push_back(p->val);
                cur += p->val;
                p = p->left;
                continue;
                
            }
            
            p = s.top();
            if (v.find(p) != v.end()) {
                
                s.pop();
            
                if (p->left == NULL && p->right == NULL && cur == sum)
                    vs.push_back(path);

                
                path.pop_back();
                cur -= p->val;
                p = NULL;
            }
            else {
                
                v.insert(p);
                p = p->right;
                
            }            
        }
                
        return vs;
    }
};
//rev.2
// class Solution {
// public:
//     vector<vector<int> > pathSum(TreeNode *root, int sum) {
//         // Start typing your C/C++ solution below
//         // DO NOT write int main() function
//         vector<vector<int> > vs;
        
//         if (!root) return vs;

//         vector<int> path;

//         pathSumWithPre(root, sum, path, vs);
                
//         return vs;
//     }
// private:
//     void pathSumWithPre(TreeNode *root, int sum, vector<int> &path, vector<vector<int> > &r) {

//         if (root->left == NULL && root->right == NULL) {

//             if (sum == root->val) {
//                 path.push_back(root->val);
//                 r.push_back(path);
//                 path.pop_back();
//             }

//             return;
//         }

//         path.push_back(root->val);

//         if (root->left)
//             pathSumWithPre(root->left, sum - root->val, path, r);

//         if (root->right)
//             pathSumWithPre(root->right, sum - root->val, path, r);

//         path.pop_back(root->val);

//         return;

//     }
// };
// class Solution {
// public:
//     vector<vector<int> > pathSum(TreeNode *root, int sum) {
//         // Start typing your C/C++ solution below
//         // DO NOT write int main() function
//         vector<vector<int> > vs;
        
//         if (!root) return vs;
        
//         if (root->left == NULL & root->right == NULL
//             && sum == root->val) {
//                 vector<int> temp;
//                 temp.push_back(sum);
//                 vs.push_back(temp);
                
//                 return vs;
//             }
            
//         if (root->left) {
//             vector<vector<int> > vs_t = pathSum(root->left, sum - root->val);
            
//             for_each(vs_t.begin(), vs_t.end(), [&vs, root](vector<int> &v) {
//                 v.insert(v.begin(), root->val);
//                 vs.push_back(v);
//             });
//         }
        
//         if (root->right) {
//             vector<vector<int> > vs_t = pathSum(root->right, sum - root->val);
            
//             for_each(vs_t.begin(), vs_t.end(), [&vs, root](vector<int> &v) {
//                 v.insert(v.begin(), root->val);
//                 vs.push_back(v);
//             });
//         }
                
//         return vs;
//     }
// };