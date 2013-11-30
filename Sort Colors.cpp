class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int idx1 = 0, idx2 = n-1;
        
        int j = 0;
        
        while (j <= idx2) {
            
            if (A[j] == 0) {
                if (j != idx1) {
                    swap(A[idx1++], A[j]);
                }
                else
                    j++;
            }
            else if (A[j] == 2) {
                
                if (j != idx2) {
                    swap(A[idx2--], A[j]);
                }
                else
                    j++;
            }
            else j++;
        }
    }
};