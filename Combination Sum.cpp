class Solution {
public:
    vector<vector<int>> cbSum(vector<int> &cans, int target, int n) {
        
        vector<vector<int>> r;
        
        if (target == 0) {
            r.push_back(vector<int>());
            return r;
        }
        
        for (int i = n-1; i >= 0; i--) {
                        
            for (int j = 1; j * cans[i] <= target; j++)
            {
                vector<vector<int>> vs = cbSum(cans, target - cans[i] * j, i);
                for (int k = 0; k < vs.size(); k++) {
                    vs[k].resize(vs[k].size() + j, cans[i]);
                    r.push_back(vs[k]);
                }
            }
            
        }
        
        return r;
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> r = cbSum(candidates, target, candidates.size());
        
        for (int i = 0; i < r.size(); i++) {
            sort(r[i].begin(), r[i].end());
        }
        
        return r;
    }
};