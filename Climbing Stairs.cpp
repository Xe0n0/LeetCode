//1. be careful that the initial may not be only one value;
class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0 || n == 1) return 1;
        
        vector<int>s(n, 0);
        
        s[0] = 1;
        s[1] = 1;
        
        for (int i = 1; i < n; i++) {
            s[i] += s[i-1];
            
            if (i > 1)
                s[i] += s[i-2];
        }
        
        return s[n-1];
    }
};