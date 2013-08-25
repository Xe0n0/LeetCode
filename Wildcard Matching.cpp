//corner cases: NULL, '' and '', '' and '*'
//size of dp, and re

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char *p_s, *p_p;

        if ((p_s = s) == NULL || (p_p = p) == NULL) return false;
        
        
        bool has_star = false;
        
        while (*p_s != '\0') {
            
            switch (*p_p) {
                case '*':
                    has_star = true;
                    p = p_p;
                    s = p_s;
                    while (*p == '*') {
                        p++;
                    }
                    if (*p == '\0') return true;
                    
                    p_s = s - 1;
                    p_p = p - 1;
                    break;
                    
                case '?':
                    break;
                    
                default:
                    if (*p_p != *p_s) {
                        if (!has_star) return false;
                        s++;
                        p_s = s-1;
                        p_p = p-1;
                    }
                    break;
                    
            }
            
            p_s++;
            p_p++;
        }
        while (*p_p == '*') p_p++;
        
        return *p_p == '\0';
        
    }
};
// class Solution {
// public:
//     bool isMatch(const char *s, const char *p) {
//         // Start typing your C/C++ solution below
//         // DO NOT write int main() function
//         const char *p_s, *p_p;
        
//         if ((p_s = s) == NULL || (p_p = p) == NULL) return false;
        
//         int h = 1, w = 1;
        
//         while (*p_s++ != '\0') {
//             h++;
//         }
//         while (*p_p++ != '\0') w++;
                
//         vector<bool>m(w, false);
        
//         m[0] = true;
        
//         for (int i = 0; i < h; i++) {
//             for (int j = w-1; j >= 0; j--) {
                
//                 if (j == 0) {
//                     if (i == 0) m[0] = true;
//                     else m[0] = false;
//                 }
//                 else
//                     switch (p[j-1]) {
//                     case '*':
                        
//                         //if (j > 0)
//                           //  m[i][j] = m[i][j] || m[i][j-1];
//                         if (i > 0 and j > 0)
//                             m[j] = m[j] || m[j-1];
//                         else
//                             m[j] = false;
//                         break;
                        
//                     case '?':
//                         if (i > 0 and j > 0)
//                             m[j] = m[j-1];
//                         else
//                             m[j] = false;
//                         break;
//                     default:
//                         if (i > 0 and j > 0)
//                             m[j] = (m[j-1] && *(p+j-1) == *(s+i-1));
//                         else
//                             m[j] = false;
//                         break;
//                 }
                
//                 int k = j;
            
//                 while (k < w-1 && p[k] == '*') {m[k+1] = m[k+1] || m[k]; k++;};
                
//             }
//         }
        
        
//         return m[w-1];
//     }
// };