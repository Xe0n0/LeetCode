class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char *p = s;
        
        if (p == NULL || *p == '\0') return false;
        
        bool meet_point = false;
        bool meet_e = false;
        bool meet_non_space = false;
        bool should_end_with_space = false;
        bool meet
        
        while (*p != '\0') {
            
            if (*p == '.') {
                
                if (meet_point) return false;
                
                meet_point = true;
            }
            
            else if (*p == 'e') {
                if (meet_e) return false;
                
                meet_e = true;
            }
            else if (!(*p >= '0' and *p <= '9') && *p != ' ')
                return false;
            
            if (*p == ' ') {
                
                if (meet_non_space) should_end_with_space = true;

            }
            else {
                
                if (should_end_with_space) return false;
                meet_non_space = true;

            }
                            
            p++;
        }
        
        if (!meet_non_space) return false;
        
        return true;
    }
};