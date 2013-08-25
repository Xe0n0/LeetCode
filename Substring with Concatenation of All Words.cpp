class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> r;
        
        int w;
        if (L.size() == 0 || (w = L[0].size()) == 0) return r;
        
        unordered_map<string, int> need;
        unordered_map<string, int> found;
        unordered_set<string> set_l;
        int count = 0;
        
        for (int i = 0; i < L.size(); i++) {
            
            need[L[i]] += 1;
            set_l.insert(L[i]);
            
        }
        
        
        for (int offset = 0; offset < w; offset++) {
            
            int i = offset;
            int begin = offset;
            count = 0;
            found.clear();
            
            while (i < S.size()) {
                
                string t = S.substr(i, w);
                if (set_l.find(t) != set_l.end()) {
                    found[t] += 1;
                    if (found[t] <= need[t])
                        count++;
                    else {
                        string t2 = S.substr(begin, w);
                        while (t2 != t) {
                            begin += w;
                            found[t2]--;
                            if (need[t2]) count--;
                            t2 = S.substr(begin, w);
                        }
                        begin += w;
                        found[t2]--; 
                    }
                    
                    if (count == L.size()) {
                        string t2 = S.substr(begin, w);
                        while (need[t2] <= 0) {
                            begin += w;
                            t2 = S.substr(begin, w);
                        }
                        r.push_back(begin);
                    }
                }
                else {
                    begin = i;
                    count = 0;
                    found.clear();
                }
                
                i += w;
            }
            
        }
        
        return r;
    }
};