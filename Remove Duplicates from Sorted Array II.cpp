class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 2) return n;
                
        int end = n - 1;
        
        for (int i = 2; i <= end; i++) {
            
            if (A[i] == A[i-1] and A[i] == A[i-2]) {
                
                for (int j = i; j < end; j++) {
                    A[j] = A[j+1];
                }
                end--;
                i--;
            }
        }
        
        return end+1;
    }
};