//1. be clear about the lower bound is >= 0
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> s(n, string(n, '.'));
        
        vector<vector<string> > r;
        
        recurseAt(r, s, 0, n);
        
        return r;
    }
    
private:
    void recurseAt(vector<vector<string> > &r, vector<string> &s, int idx, int n) {
        
        for (int i = 0; i < n; i++) {
            
            s[idx][i] = 'Q';
            
            if (isValid(s, idx, i)) {
                
                if (idx >= n - 1) {
                    
                    r.push_back(s);
                    
                }
                else
                    recurseAt(r, s, idx+1, n);
            }
            s[idx][i] = '.';

        }
    }
    
    bool isValid(vector<string> &s, int row, int col) {
        
        for (int i = 0; i < s.size(); i++) {
            
            if (i == row) continue;
            
            int d = abs(row - i);
            if (col - d >= 0 && s[i][col-d] == 'Q')
                return false;
            
            if (col + d < s.size() && s[i][col+d] == 'Q')
                return false;
                
            if (s[i][col] == 'Q')
                return false;
        }
        
        return true;
        
    }
};