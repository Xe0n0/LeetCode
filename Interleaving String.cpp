class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (s3.size() != (s1.size() + s2.size())) return false;
                
        vector<vector<bool>> isPrefix(s1.size()+1, vector<bool>(s2.size()+1, false));
        
        isPrefix[0][0] = true;
        
        for (int i = 0; i <= s1.size(); i++) {
            
            for (int j = 0; j <= s2.size(); j++) {
                
                if (i > 0) {
                    
                    isPrefix[i][j] = isPrefix[i-1][j] && s1[i-1] == s3[i+j-1];
                    
                }
                
                if (j > 0) {
                    
                    isPrefix[i][j] = isPrefix[i][j] || isPrefix[i][j-1] && s2[j-1] == s3[i+j-1];
                    
                }
                
            }
        }
        
        return isPrefix[s1.size()][s2.size()];
    }
};