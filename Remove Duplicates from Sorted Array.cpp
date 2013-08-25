// 1.be care of which one comes first, end-- or copy data
// 2.which order should the result have? keep origin?
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        int end = n - 1;
        
        for (int i = 1; i <= end; i++) {
            
            if (find(A, A+i, A[i]) != A+i) {
                
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