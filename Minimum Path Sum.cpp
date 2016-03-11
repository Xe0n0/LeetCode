class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = grid.size();
        
        if (m <= 0) return 0;
        
        int n = grid[0].size();
        
        if (n <= 0) return 0;
        
        vector<int> lest(n, 0);
        
        lest[0] = grid[0][0];
        
        for (int i = 1; i < n; i++) {
            
            lest[i] = grid[0][i] + lest[i-1];
        }
        
        for (int i = 1; i < m; i++) {
            
            for (int j = 0; j < n; j++) {
                                
                if (j > 0)
                    lest[j] = min(lest[j-1], lest[j]) + grid[i][j];
                else
                    lest[j] += grid[i][j];
            }
        }
        
        return lest[n-1];
    }
};