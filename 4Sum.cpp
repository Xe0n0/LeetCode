#define wu_map unordered_multimap<int, pair<int, int>>
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > r;
        
        sort(num.begin(), num.end());
        unordered_multimap<int, pair<int, int>> sums;
        
        
        for (int i = 0; i < num.size(); i++) {
            
            for (int j = i + 1; j < num.size(); j++) {
                
                sums.insert(make_pair(num[i]+num[j], make_pair(i, j)));
                
            }
        }
        
        auto it = sums.begin();
        
        while (it != sums.end()) {
            
            int t = target - it->first;
            
            //if (t >= *it) {
                
                auto range = sums.equal_range(t);
                
                for_each(
                    range.first,
                    range.second,
                    [&r, &it, &num](pair<const int, pair<int, int>>& x){
                        if (x.second.first > it->second.second) {
                            vector<int> temp;
                            temp.push_back(num[it->second.first]);
                            temp.push_back(num[it->second.second]);
                            temp.push_back(num[x.second.first]);
                            temp.push_back(num[x.second.second]);
                            sort(temp.begin(), temp.end());
                            r.push_back(temp);
                        }
                    }
                    );
                
            //}
            
            it++;
        }
        
        sort(r.begin(), r.end(),
            [](const vector<int>&a, const vector<int>&b){
            
                for (int i = 0; i < 4; i++) {
                    if (a[i] != b[i]) {
                        return a[i] < b[i];
                    };
                }
                
                return 0;
                
            });
        
        auto it2 = unique(r.begin(), r.end(), 
            [](const vector<int>&a, const vector<int>&b){
            
                for (int i = 0; i < 4; i++) {
                    if (a[i] != b[i]) return false;
                }
                
                return true;
                
            });
            
        r.resize(it2 - r.begin());
        
        
        return r;
    }
};