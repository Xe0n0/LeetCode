class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = triangle.size();
        
        if (n == 0) return 0;
        
        vector<int> sum(triangle[n-1]);
        
        for (int i = triangle.size() - 2; i >= 0; i--) {
            
            for (int j = 0; j < triangle[i].size(); j++) {
                
                if (j + 1 < triangle[i+1].size())
                
                    sum[j] = triangle[i][j] + min(sum[j], sum[j+1]);
                    
                else
                
                    sum[j] += triangle[i][j];
            }
        }
        
        return sum[0];
    }
};