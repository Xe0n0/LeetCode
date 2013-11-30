//O(n^2) to compute height of bar for each i, j, use O(n) to caculate largest rectangle
//in a line of bars for each n, thus O(n^2) overall;
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int w, h;
        
        if ((h = matrix.size()) == 0 || (w = matrix[0].size()) == 0) return 0;
        
        vector<vector<int>> h_bars(h, vector<int>(w, 0));
        
        for (int i = 0; i < h; i++) {
            
            for (int j = 0; j < w; j++) {
                
                if (0 == i) {
                    h_bars[i][j] = matrix[i][j] == '1' ? 1 : 0;
                }
                else
                    h_bars[i][j] = matrix[i][j] == '1' ? matrix[i-1][j] + 1 : 0;
                
            }
        }
        
        int max_area = 0;
        stack<int> bars;
        
        for (int i = 0; i < h; i++) {
            
            bars.clear();
            int j = 0;
                        
            while (j < w) {
                
                if (bars.empty() || bars.top() < h_bars[i][j]) {
                    bars.push(j);
                    j++;
                }
                else {
                    
                    int idx = bars.top();
                    bars.pop();
                    max_area = max(max_area, (j-idx) * h_bars[i][idx]);
                    
                }
                while (!bars.empty()) {
                    int idx = bars.top();
                    bars.pop();
                    max_area = max(max_area, (w-idx) * h_bars[i][idx]);
                }
            }
            
        }
        
        return max_area;
        
    }
};