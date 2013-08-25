// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include <stack>
#include <vector>

using namespace std;
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
                else {
                    if (matrix[i][j] == '1') {
                        h_bars[i][j] = h_bars[i-1][j] + 1;
                    }
                    else
                        h_bars[i][j] = 0;
                }
                
                cout << i << ' ' << j << ' ' << h_bars[i][j] << endl;
            }
        }
        
        int max_area = 0;
        for (int i = 0; i < h; i++) {
            
            stack<int> bars;
            
            int j = 0;
            cout << i <<endl;
            while (j < w) {
                
                if (bars.empty() || h_bars[i][bars.top()] <= h_bars[i][j]) {
                    bars.push(j);
                    j++;
                    
                    if (bars.empty())
                        max_area = max(max_area, j * h_bars[i][j]);
                    
                    cout << j << ':' << max_area << endl;
                }
                else {
                    cout << "fi" <<endl;
                    int idx = bars.top();
                    bars.pop();
                    max_area = max(max_area, (j-idx) * h_bars[i][idx]);
                    cout << j << ' ' << "idx:" << idx << 'h' << ' ' << h_bars[i][idx] << max_area << endl;
                    
                }
                
                
            }
            cout << "pop" <<endl;
            while (!bars.empty()) {
                    int idx = bars.top();
                    bars.pop();
                    max_area = max(max_area, (w-idx) * h_bars[i][idx]);
                    cout << idx << ' ' << max_area << endl;
            }
            
        }
        
        return max_area;
        
    }
};
int main() {
    // Start typing your code here...
    vector<vector<char> > temp({{'1', '0'}});
    cout << Solution().maximalRectangle(temp) << endl;
    
    
    return 0;
}