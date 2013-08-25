class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //int i = S.size(), j = 0;
        
        string r;
        
        if (T.size() == 0) return r;
        
        int count = S.size(), start = 0;
        
        vector<int>total(256, 0);
        vector<int>need(256, 0);
        
        for (int i = 0; i < T.size(); i++) {
            
            need[T[i]] += 1;
            
        }
        
        int found = 0;
        
        int p = 0;
        
        for (int i = 0; i < S.size(); i++) {
            
            if (need[S[i]] == 0) continue;
            
            total[S[i]]++;
            
            if (total[S[i]] <= need[S[i]]) found++;
            
            if (found == T.size()) {
                
                while (total[S[p]] > need[S[p]] || need[S[p]] == 0) {
                    
                    if (total[S[p]]) total[S[p]]--;
                    
                    p++;
                }
                
                if (i - p + 1 < count) {count = i - p + 1; start = p;}
                
            }
            
        }
        
        if (found != T.size()) return r;
        
        
        return S.substr(start, count);
    }
};