//rev.1 revised
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.size() == 0) return 0;
                
        int max_length = 1;
        
        unordered_map<char, int> counts;
        
        int idx = 0;
        
        for (int i = 0; i < s.size(); i++) {
            
            counts[s[i]]++;
            
            while (counts[s[i]] > 1) {
                counts[s[idx]]--;
                idx++;
            }
            
            max_length = max(max_length, i - idx + 1);
            
        }
        
        return max_length;
    }
};
//rev.2
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