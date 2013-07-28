//1. should look back to ensure find out longest no-repeating chars substr
//ending at index i, when a repeat found.

class Solution {
private:
    vector<bool> flags;
    void clear_flags() {
        for (int i = 0; i< flags.size(); i++) {
            flags[i] = false;
        }
    }
public:
    Solution (){
        flags.resize(256, false);
    }
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int longest_len = 0;
        int len = 0;
        clear_flags();
        
        for (int i = 0; i < s.size(); i++) {
            if (flags[s[i]]) {
                len = 1;
                
                clear_flags();
                flags[s[i]] = true;

                while (i - len >= 0 && !flags[s[i-len]]) {
                    flags[s[i - len]] = true;
                    len++;
                }
            }
            else {
                len++;
                flags[s[i]] = true;
            }
            longest_len = max(len, longest_len);
        }
        
        return longest_len;

    }
};