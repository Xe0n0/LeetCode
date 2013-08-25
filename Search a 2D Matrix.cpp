class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (matrix.size() == 0) return false;
        
        if (matrix[0].size() == 0) return false;
        
        int a = 0;
        int b = matrix.size() - 1;
        
        while (a < b) {
            
            if (matrix[(a+b)/2][0] > target) {
                b = (a+b)/2 - 1;
            }
            else if (matrix[(a+b)/2][0] < target) {
                a = (a+b)/2 + 1;
            }
            else return true;
        }
        
        if (matrix[a][0] > target) {
            if (a - 1 >= 0)
                return binary_search(matrix[a-1].begin(), matrix[a-1].end(), target);
        }
        else {
            
                return binary_search(matrix[a].begin(), matrix[a].end(), target);
        }
     
        return false;
    }
};