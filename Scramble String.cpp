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