class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (word.size() == 0) return true;
        if (board.size() == 0 || board[0].size() == 0) return false;
        
        int h = board.size();
        int w = board[0].size();
        
        vector<vector<bool>> flags(h, vector<bool>(w, false));
        
        for (int i = 0; i < board.size(); i++) {
            
            for (int j = 0; j < board[0].size(); j++) {
                
                if (board[i][j] == word[0]) {
                    if (dfs(board, i, j, word, 1, flags))
                        return true;
                }
                
            }
            
        }
        
        return false;
    }
private:
    bool dfs(vector<vector<char>> &board, int x, int y, 
        string word, int idx, vector<vector<bool>>& flags) {
        
        if (idx == word.size()) return true;
        
        if (!flags[x][y]) {
            
            flags[x][y] = true;
            
            for (int i = x-1; i <= x+1; i++) {
                
                for (int j = y-1; j <= y+1; j++) {
                    
                    if (i < 0 || i >= board.size()) continue;
                    
                    if (j < 0 || j >= board[0].size()) continue;
                    
                    if (abs(i - x) + abs(j-y) > 1) continue;
                                        
                    if (!flags[i][j] && word[idx] == board[i][j]) {
                        if (dfs(board, i, j, word, idx+1, flags))
                            return true;
                    }
                    
                }
            }
            flags[x][y] = false;
            
        }
        
        return false;
    }
};