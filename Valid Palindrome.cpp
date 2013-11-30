//O(n)
class Solution {
private:
    bool isAlphanumeric(char& c) {
        if (c >= '0' and c <= '9') return true;
        if (c >= 'a' and c <= 'z') return true;
        if (c >= 'A' and c <= 'Z') {
            
            c -= 'A' - 'a';
            
            return true;
            
        }
        
        return false;
    }
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        int j = s.size() - 1;
        
        while (i < j) {
            if (!isAlphanumeric(s[i])) {
                i++;
                continue;
            }
            if (!isAlphanumeric(s[j])) {
                j--;
                continue;
            }
            if (s[i] != s[j])
                return false;
                
            i++;
            j--;
        }
        
        return true;
    }
};