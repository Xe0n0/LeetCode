// O(k*k)
//1. rowIndex != 
//2. consider clearly override iteration direction
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> r(rowIndex + 1, 1);
        
        for (int n = 2; n <= rowIndex + 1; n++) {
            
            for (int i = n - 2; i > 0; i--) {
                
                r[i] += r[i-1];
            }
        }
        
        return r;
    }
};