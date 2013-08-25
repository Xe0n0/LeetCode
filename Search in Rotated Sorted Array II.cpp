class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 0) return false;
        
        if (n == 1) return A[0] == target;
        
        int mid = n / 2;
        
        if (A[mid] == target) return true;
        
        else if (A[mid] > A[0]) {
            if (binary_search(A, A+mid, target))
                return true;
            
            if (search(A+mid+1, n - mid-1, target))
                return true;
        }
        else if (A[mid] < A[0]) {
            if (binary_search(A+mid+1, A+n, target))
                return true;
            
            if (search(A, n-mid-1, target))
                return true;
        }
        
        return search(A, mid, target) || search(A+mid, n-mid,target);
    }
};