class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.size() == 0) return;
        
        bool clear_first_row = false;
        bool clear_first_col = false;
        
        for (int i = 0; i < matrix[0].size(); i++) {
            
            if (matrix[0][i] == 0) {
                clear_first_row = true;
                break;
            }
        }
        
        for (int i = 0; i < matrix.size(); i++) {
            
            if (matrix[i][0] == 0) {
                clear_first_col = true;
                break;
            }
            
        }
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                                
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
                
            }
        }
        
        for (int i = 1; i < matrix[0].size(); i++) {
            
            if (matrix[0][i] == 0) {
                for (int j = 0; j < matrix.size(); j++) {
                    
                    matrix[j][i] = 0;
                    
                }
            }
        }
        
        for (int i = 1; i < matrix.size(); i++) {
            
            if (matrix[i][0] == 0) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    
                    matrix[i][j] = 0;
                    
                }
            }
            
        }
        if (clear_first_row) {
            
            for (int i = 0; i < matrix[0].size(); i++) {
                
                matrix[0][i] = 0;
                
            }
        }
        
        if (clear_first_col) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
        
    }
};