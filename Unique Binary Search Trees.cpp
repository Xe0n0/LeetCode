class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 0;
        
        if (n == 1) return 1;
        
        int r = 0;
        
        r += 2 * numTrees(n - 1);
        
        for (int i = 1; i < n - 1; i++) {
            
            r += numTrees(i) * numTrees(n - i - 1);
            
        }
        
        return r;
    }
};