//1. I forget the last i++ and j++, damn!
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (A == NULL || B == NULL || n == 0) return;
        
        int *temp = new int[m + n];
        int *p = temp;
        
        int i = 0, j = 0;
        
        while (i < m && j < n) {
            
            if (A[i] < B[j]) {
                
                *p++ = A[i++];
                
            } else {
                
                *p++ = B[j++];
                
            }
        }
        
        while (i < m) {
            
            *p++ = A[i++];
            
        }
        
        while (j < n) {
            
            *p++ = B[j++];
            
        }
        
        for (int k = 0; k < m + n; k++) {
            A[k] = temp[k];
        }
    }
};