//1. what should be return if needle is NULL
//2. some condition prevent go inside loop may have satifiable pattern
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        char *r = NULL;
        
        if (haystack == NULL || needle == NULL) return r;
        
        char *c_start = haystack;
        
        if (*haystack == '\0' and *needle == '\0') return haystack;
        
        while (*c_start != '\0') {
            
            bool found = true;
            char *c = c_start;
            char *p = needle;
            
            while (*c != '\0' and *p != '\0') {
                if (*c++ != *p++) {
                    found = false;
                    break;
                }
            }
            if (found && *c == '\0' && *p != '\0') break;
            
            if (found) {
                r = c_start;
                break;
            }
            
            c_start++;
        }
        
        return r;
    }
};