class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        //so that we can igore the center point
        vector<vector<int> > r(n ,vector<int>(n, n*n));
                
        if (n <= 0) return r;
        
        int num = 1;

        
        for (int d = 0; d < n/2; d++) {
            
            for (int i = d; i < n - d; i++)
                r[d][i] = num++;
                
            for (int i = d+1; i < n-d; i++)
                r[i][n-d-1] = num++;
                
            for (int i = n-d-2; i >= d; i--)
                r[n-d-1][i] = num++;
            
            for (int i = n-d-2; i > d; i--)
                r[i][d] = num++;
        }
        
        return r;
    }
};