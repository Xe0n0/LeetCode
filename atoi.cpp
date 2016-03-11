class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (str == NULL) return 0;
        
        const char *p = str;
        
        bool negative = false;
        
        unsigned r = 0;
        
        while (*p != 0) {
            
            if (*p == ' ') {
                
                p++;
                continue;
            }
            else {
                
                if (*p == '+' or *p == '-') {
                    
                    negative = (*p == '-');
                    p++;
                }
                
                while (*p >= '0' and *p <= '9') {
                    
                    r *= 10;
                    r += *p - '0';
                    p++;
                    
                    if (negative and (unsigned)r > (unsigned)INT_MAX + 1) {r = INT_MIN;break;}
                    if (!negative and (unsigned)r > (unsigned)INT_MAX) {r = INT_MAX;break;}
                    
                }
                
                if (negative)
                    r = -r;
                    
                
                    
                break;
            }
        }
        
        return r;
    }
};