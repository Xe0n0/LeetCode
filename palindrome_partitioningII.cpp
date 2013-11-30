// solution 2, Dynamic Programming for judge isPalin, O(n^2) and use O(n^2) to calc count
class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // f(i, j) = f(i+1, j-2) && s[i] == s[s+j]
        int n = s.size();
        
        if (n == 0) return true;
        
        vector<vector<bool>> isPalin(n, vector<bool>(n + 1, false));
        
        for (int i = 0; i < n; i++) {
            isPalin[i][0] = true;
            isPalin[i][1] = true;
        }
        
        for (int i = 2; i <= n; i++) {
            
            for (int j = n - i; j >= 0; j--) {
                
                if (j + i - 1 > n - 1) continue;
                
                if (s[j] == s[j+i-1])
                    isPalin[j][i] = isPalin[j+1][i-2];
                else
                    isPalin[j][i] = false;
                
            }
            
        }
        
        vector<int> count(n, INT_MAX);
        count[n-1] = 0;
        
        for (int i = n-2; i >= 0; i--) {
            if (isPalin[i][n-i]) {
                    count[i] = 0;
                    continue;
            }
            for (int j = i + 1; j < n; j++) {
                
                if (isPalin[i][j-i])
                    count[i] = min(count[i], count[j] + 1);
            }
            
        }
        
        return count[0];
        
    }
};
// solution 1. recusively, each level use O(n) * O(n) to decide palindrome and use O(1) to retrieve next count
// total O(n^3)
// class Solution {
// public:
//     int* count;
//     bool isPalindrome(const string &s, int start, int index){
//         int i = start, j = index - 1;
        
//         while (i < j){
//             if (s[i] != s[j]){
//                 //cout << s[i] << s[j] << i << j << endl;
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }
    
//     int minCutAt(int index, const string& s){
//         if (index < s.size()){
            
//             if (count[index] < 0){
                
//                 if (isPalindrome(s, index, s.size()))
//                 {
//                     count[index] = 0;
//                     return 0;
//                 }

//                 int minThrehold = s.size() - index;
//                 for (int i = s.size() - 1; i > index; i--){
                
                
//                     if (isPalindrome(s, index, i)) {
                    
//                         minThrehold = min(minCutAt(i, s) + 1, minThrehold);
//                         if (minThrehold <= 1) break;
//                     }
//                 }
//                 count[index] = minThrehold;
                
//             }
//             return count[index];
             
//         }
//         return 0;
//     }
//     int minCut(string& s) {
//         // Start typing your C/C++ solution below
//         // DO NOT write int main() function
      
            
//             count = new int[s.size()];
//             for (int i = 0; i < s.size(); i++){
//                 count[i] = -1;
//             }
      
        
//         return minCutAt(0, s);
//     }
// };