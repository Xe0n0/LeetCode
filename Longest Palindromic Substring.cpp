class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int best_pivot = 0;
        int best_len = 0;
        
        int len = 0;
        
        for (int i = 0; i < s.size(); i++) {
            
            len = 1;
            
            for (int j = i - 1; j >= 0 && 2 * i - j < s.size(); j--) {
                if (s[2 * i - j] != s[j]) break;
                len += 2;
            }
            if (len > best_len) {
                best_len = len;
                best_pivot = i;
            }
        }
        
        for (int i = 0; i < s.size() - 1; i++) {
            
            len = 0;
            
            for (int j = i; j >= 0 && 2 * i + 1 - j < s.size(); j--) {
                if (s[2*i+1-j] != s[j]) break;
                len += 2;
            }
            if (len > best_len) {
                best_len = len;
                best_pivot = i;
            }
        }
        
        if (best_len % 2 == 0) {
            return s.substr(best_pivot + 1 - best_len/2, best_len);
        }
        return s.substr(best_pivot - best_len/2, best_len);
    }
};