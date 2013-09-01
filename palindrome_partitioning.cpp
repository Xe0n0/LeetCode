//solution rev.2 dp over isPalin and not copy from subproblem, n^2 to get isPalin, but the recursion cost much
class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n;
        vector<vector<string>> r;
        
        if ((n = s.size()) == 0) return r;
        
        vector<vector<bool>>isPalin(n + 1, vector<bool>(n + 1, false));
        
        for (int len = 0; len <= n; len++) {
            
            for (int i = 0; i <= n - len; i++) {
                
                if (len == 0 || len == 1 || isPalin[i+1][len-2] && s[i] == s[i+len-1])
                    isPalin[i][len] = true;
                
            }
        }
        vector<string> path;
        partitionAt(s, 0, path, r, isPalin);
        
        return r;
    }
private:
    void partitionAt(string &s, int start,
        vector<string> &path, vector<vector<string>> &r, vector<vector<bool>> &isPalin) {
            
            if (start == s.size()) {
                r.push_back(path);
                return;
            }
            
            for (int i = start; i < s.size(); i++) {
                
                if (isPalin[start][i-start+1]) {
                    path.push_back(s.substr(start, i-start+1));
                    partitionAt(s, i+1, path, r, isPalin);
                    path.pop_back();
                }
                
            }
            
            return;
            
        }
};
// solution 1
// class Solution {
// private:
//     bool isPalindrome(string s){
//         int i = 0, j = s.size() - 1;
//         while (i < j){
//             if (s[i] != s[j]) return false;
//             i++;
//             j--;
//         }
//         return true;
//     }
// public:
//     vector<vector<string>> partition(string s) {
//         // Start typing your C/C++ solution below
//         // DO NOT write int main() function
//         vector<vector<string>> partitions;
        
//         if (s.size() > 0){
//             for (int i = 1; i <= s.size(); i++){
//                 string a = s.substr(0, i);
//                 if (isPalindrome(a)) {
                    
//                     vector<vector<string>> yapartions = partition(s.substr(i));
//                     for (int j = 0; j < yapartions.size(); j++){
//                         vector<string> temp;
//                         temp.push_back(a);
//                         for (int k = 0; k < yapartions[j].size(); k++){
//                             temp.push_back(yapartions[j][k]);
//                         }
//                         partitions.push_back(temp);
//                     }
//                 }
//             }
//         }
//         else {
//             vector<string> temp;
//             //temp.push_back(s);
//             partitions.push_back(temp);
//         }
//         return partitions;
//     }
// };