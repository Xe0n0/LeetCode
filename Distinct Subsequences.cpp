// reduce space cost
class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> num(T.size() + 1, 0);
        
        num[0] = 1;
        
        for (int j = 1; j <= S.size(); j++) {
            
            for (int i = T.size(); i >= 0; i--) {
                
                if (i == 0)
                    num[i] = 1;
                    
                else {
                    
                    num[i] += (T[i-1] == S[j-1]) ? num[i-1] : 0;
                    
                }
                
            }
        }
        
        return num[T.size()];
    }
};
// //1. when dp, be careful of table size.
// //2. be careful of judgement index.
// class Solution {
// public:
//     int numDistinct(string S, string T) {
//         // Start typing your C/C++ solution below
//         // DO NOT write int main() function
//         vector<vector<int>> num(S.size(), vector<int>(T.size(), 0));
        
//         if (S.size() < T.size()) return 0;
        
//         if (S.size() == 0 || T.size() == 0) return 0;
        
//         for (int j = 0; j < T.size(); j++) {
            
//             for (int i = 0; i < S.size(); i++) {
                
//                 if (j == 0) {
                    
//                     if (i == 0)
//                         num[i][j] = (S[0] == T[0]?1:0);
//                     else
//                         num[i][j] = num[i-1][j] + (S[i] == T[j]?1:0);
//                 }
//                 else {
//                     if (i == 0) {
                        
//                         num[i][j] = 0;
                        
//                     }
//                     else
//                         num[i][j] = num[i-1][j] + (S[i] == T[j]?num[i-1][j-1]:0);
//                 }
                
//             }
            
//         }
        
//         return num[S.size()-1][T.size()-1];
//     }
// };