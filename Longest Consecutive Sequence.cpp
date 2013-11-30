//O(n), each num will only be reached by once after set built
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_set<int> occur(num.begin(), num.end());
        int max_len = 0;
        
        for (int i = 0; i < num.size(); i++) {
            
            if (occur.find(num[i]) == occur.end()) continue;
            
            int len = 1;
            
            int next = num[i] + 1;
            
            while (occur.find(next) != occur.end()) {
                
                occur.erase(next);
                next++;
                
            }
            
            len += next - num[i] - 1;
            
            next = num[i] - 1;
            
            while (occur.find(next) != occur.end()) {
                
                occur.erase(next);
                next--;
            }
            
            occur.erase(next);
            
            len += num[i] - next - 1;
            
            max_len = max(max_len, len);
            
        }
        
        return max_len;
    }
};