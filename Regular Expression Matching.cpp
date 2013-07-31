//what if patterns like '*.'
//mistake: change push_back(i) to push_back(i+1) but forget to move that line down,
//thus cause cause s overflow

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (*s == '\0' and *p == '\0') return true;
        else if (*p == '\0') return false;
        
        vector<int> pos;
        
        bool withStar = false;
        
        switch (*p) {
            case '*':
                return false;
                break;
            default:
            
                if (*(p+1) == '*')
                    withStar = true;
                    
                if (withStar) {
                    pos.push_back(0);
                    
                    for (int i = 0; s[i] == *p or *p == '.';i++) {                        
                        if (s[i] == '\0') break;
                        pos.push_back(i+1);

                    }
                    
                }
                else {
                    if (*p == *s or *p == '.' and *s != '\0') pos.push_back(1);
                }
                                
                break;
        }
        
        if (withStar) {
            const char *p_next = p + 2;
            for (int i = 0; i < pos.size(); i++) {
            if (isMatch(s+pos[i], p_next)) return true;
        }
        }
        else {
            const char *p_next = p + 1;
            for (int i = 0; i < pos.size(); i++) {
            if (isMatch(s+pos[i], p_next)) return true;
        }
        }
        
        
        return false;
    }
};