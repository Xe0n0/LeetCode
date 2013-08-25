class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.size() == 0) return 0;
        
        vector<int> length(s.size(), 1);
        
        int max_length = 1;
        
        unordered_set<char> occur;
        occur.insert(s[0]);
        
        for (int i = 1; i < s.size(); i++) {
            
            if (occur.find(s[i]) == occur.end()) {
                occur.insert(s[i]);
                length[i] = length[i-1] + 1;
            }
            else {
                occur.clear();
                
                int j = i;
                
                while (j >= 0 && occur.find(s[j]) == occur.end()) {
                    
                    occur.insert(s[j]);
                    j--;
                    
                }
                length[i] = i-j;
            }
            
            max_length = max(max_length, length[i]);
        }
        
        return max_length;
    }
};