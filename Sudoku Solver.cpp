class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        couldSolveSudoku(board);
    }
    bool couldSolveSudoku(vector<vector<char> > &board) {
        
        for (int i = 0; i < 9; i++) {
            
            for (int j = 0; j < 9; j++) {
                
                
                if (board[i][j] != '.') continue;
                
                for (char k = '1'; k <= '9'; k++) {
                    
                    board[i][j] = k;
                    
                    if (isValid(board, i, j) && couldSolveSudoku(board))
                        return true;
                    
                    board[i][j] = '.';
                }
                
                return false;
                
            }
        }
        
        return true;
        
    }
private:
    bool isValid(vector<vector<char> > &board, int x, int y) {
        
        
        for (int i = 0; i < 9; i++) {
            if (i != y and board[x][i] == board[x][y])
                return false;
        }
        
        
        for (int i = 0; i < 9; i++) {
            
            if (i != x and board[i][y] == board[x][y])
                return false;
        }
        
        for (int i = x / 3 * 3; i < (x/3+1)*3; i++) {
            for (int j = y / 3 * 3; j < (y/3+1)*3; j++) {
                
                if (i == x and j == y) continue;
                
                if (board[i][j] == board[x][y])
                    return false;                
            }
        }
        
        return true;
        
    }
};