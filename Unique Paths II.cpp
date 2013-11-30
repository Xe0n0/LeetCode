class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        
        if (m <= 0) return 0;
        
        int n = obstacleGrid[0].size();
        
        if (n <= 0) return 0;
        
        if (obstacleGrid[0][0]) return 0;
        
        vector<vector<int> > grid(m, vector<int>(n, 0));

        grid[0][0] = 1;
        
        for (int i = 0; i < m; i++) {
            
            for (int j = 0; j < n; j++) {
                
                if (obstacleGrid[i][j]) continue;
                
                if (i > 0) 
                    grid[i][j] += grid[i-1][j];
                
                if (j > 0)
                    grid[i][j] += grid[i][j-1];
            }
        }
        
        return grid[m-1][n-1];
    }
};