class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        
        unordered_map<int, int> counts;
        
        for_each(num.begin(), num.end(), [&counts](int &t){
        
            if (counts.find(t) == counts.end()) {
                counts[t] = 0;
            }
            
            counts[t] += 1;
            
        });
        
        vector<int>::iterator it = unique(num.begin(), num.end());
        
        num.resize(distance(num.begin(), it));
        
        return permuteWithCount(counts, num);
    }
private:
    vector<vector<int> > permuteWithCount(unordered_map<int, int> &counts, vector<int> &num) {
        
        vector<vector<int> > vps;
        
        bool not_found = true;
        
        for (int i = 0; i < num.size(); i++) {
            
            if (counts[num[i]] > 0) {
                counts[num[i]] -= 1;
                vector<vector<int> > temp = permuteWithCount(counts, num);
                
                for_each(temp.begin(), temp.end(), [&vps, &num, &i](vector<int> &t){
                   
                   t.insert(t.begin(), num[i]);
                   vps.push_back(t);
                   
                });
                counts[num[i]] += 1;
                not_found = false;
            }
        }
        
        if (not_found) {
            vps.push_back(vector<int>());
        }
        
        return vps;
    }
};