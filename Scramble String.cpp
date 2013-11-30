//rev.2 3-dimension DP, O(n^4)
class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n;
        
        if ((n = s1.size()) != s2.size()) return false;
        
        if (s1 == s2) return true;
        
        string t1 = s1;
        string t2 = s2;
        
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        
        if (t1 != t2) return false;
        
        vector<vector<vector<bool> > > s(n+1, vector<vector<bool> >(n, vector<bool>(n, false)));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                s[1][i][j] = (s1[i] == s2[j]);
                
            }
        }
        for (int l = 2; l <= n; l++) {
            
            for (int i = n-1; i - l + 1 >= 0; i--) {
                
                for (int j = n-1; j - l + 1 >= 0; j--) {
                    
                    for (int k = 1; k < l; k++) {
                        
                        if (s[k][i][j-l+k] && s[l-k][i-k][j] ||
                            s[k][i][j] && s[l-k][i-k][j-k])
                            {
                                s[l][i][j] = true;
                                break;
                            }
                        
                    }
                    
                }
            }
            
        }
        return s[n][n-1][n-1];
    }
};
//rev.1
class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s1.size() != s2.size()) return false;
        if (s1.size() == 0) return true;
        if (s1 == s2) return true;
        
        int n = s1.size();
        
        unordered_set<char> counts;
        unordered_set<char> counts2;
        
        int i = 0;
        
        while (i < s1.size() - 1) {
            
            if (counts.find(s1[i]) == counts.end())
                counts.insert(s1[i]);
            else
                counts.erase(s1[i]);
                
            if (counts.find(s2[i]) == counts.end())
                counts.insert(s2[i]);
            else
                counts.erase(s2[i]);
                
            if (counts2.find(s1[i]) == counts2.end())
                counts2.insert(s1[i]);
            else
                counts2.erase(s1[i]);
                
            if (counts2.find(s2[n-i-1]) == counts2.end())
                counts2.insert(s2[n-i-1]);
            else
                counts2.erase(s2[n-i-1]);
                
            if (counts.size() == 0)
            {
                
                if (isScramble(s1.substr(0, i+1), s2.substr(0, i+1)) &&
                    isScramble(s1.substr(i+1, s1.size()-i-1), s2.substr(i+1, s2.size()-i-1)))
                    
                    return true;            
                    
            }
            
            if (counts2.size() == 0)
            {
                if (isScramble(s1.substr(0, i+1), s2.substr(n-i-1, i+1)) &&
                    isScramble(s1.substr(i+1, s1.size()-i-1), s2.substr(0, s2.size()-i-1)))
                    return true;
            }
            
            i++;
        }
        return false;
    }
};