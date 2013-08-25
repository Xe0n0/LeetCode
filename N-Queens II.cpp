//1. compare the complexity between later judge and pre filter;
class Solution {
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > s(n, vector<int>(n, 0));
        
        int num = 0;
        
        recurseAt(num, s, 0, n);
        
        return num;
    }
    
private:
    void recurseAt(int &num, vector<vector<int> > &s, int idx, int n) {
        
        for (int i = 0; i < n; i++) {
                        
            if (s[idx][i] > 0) continue;

            //s[idx][i] = -1;

            if (idx >= n - 1) {
                    
                num++;
    
            }
            else {
                setInvalid(s, idx, i);
                recurseAt(num, s, idx+1, n);
            }
            
            //s[idx][i] = '.';
            setValid(s, idx, i);

        }
    }
    
    void setInvalid(vector<vector<int> > &s, int row, int col) {
        
        for (int i = row+1; i < s.size(); i++) {
                        
            int d = i - row;
            
            if (col - d >= 0) s[i][col-d]++;
            
            if (col + d < s.size()) s[i][col+d]++;
                
            s[i][col]++;
        }
                
    }
    
    void setValid(vector<vector<int> > &s, int row, int col) {
        for (int i = row+1; i < s.size(); i++) {
                        
            int d = i - row;
            
            if (col - d >= 0) s[i][col-d]--;
            
            if (col + d < s.size()) s[i][col+d]--;
                
            s[i][col]--;
        }
    }
};