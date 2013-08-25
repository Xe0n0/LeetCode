//parethesis of ?:
class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > d(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        
        for (int i = 0; i <= word1.size(); i++) {
            
            d[i][0] = i;
            
        }
        
        for (int j = 0; j <= word2.size(); j++) {
            
            d[0][j] = j;
        }
        
        
        
        for (int i = 1; i <= word1.size(); i++) {
            
            for (int j = 1; j <= word2.size(); j++) {
                
                d[i][j] = min(d[i][j-1] + 1, d[i-1][j] + 1);
                d[i][j] = min(d[i][j], d[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0:1));
            }
        }
        
        return d[word1.size()][word2.size()];
    }
};