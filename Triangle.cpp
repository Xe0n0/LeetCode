//O(h*h)
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n;
        
        if ((n = triangle.size()) == 0) return 0;
        
        int w = triangle[n-1].size();
        
        vector<int> sums(triangle[n-1].begin(), triangle[n-1].end());
        
        for (int i = w-2; i >= 0; i--) {
            
            
            for (int j = 0; j <= i; j++) {
                
                sums[j] = min(sums[j], sums[j+1]) + triangle[i][j];
                
            }
            
        }
        
        return sums[0];
    }
};