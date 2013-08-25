//1. is 01 valid when dual decode? and 10 ?
class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.size() == 0) return 0;
        
        vector<int> counts(s.size(), 0);
        
        for (int i = 0; i < s.size(); i++) {
            
            if (s[i] >= '1' and s[i] <= '9') {
                if (i > 0)
                    counts[i] = counts[i-1];
                else
                    counts[i] = 1;
            }
            
            if (i > 0) {
                int t = stoi(s.substr(i-1, 2));
                
                if (t <= 26 and t >= 10) {
                    if (i > 1)
                        counts[i] += counts[i-2];
                    else
                        counts[i] += 1;

                }
                       
            }
                
            
        }
        
        return counts[s.size() - 1];
    }
};