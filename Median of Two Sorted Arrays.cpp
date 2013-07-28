//several ways to solve the problem
//1. find k of two sorted array
//2. binary search like
//3. drop equal amount numbers and sovle subproblem
class Solution {
private:
    double medianOfArray(int A[], int m) {
        if (m % 2 == 0) {
            return (A[m/2] + A[m/2 + 1]) / 2.0;
        }
        
        return A[m/2 + 1];
    }
    double findNumberKSortedArrays(int A[], int m, int B[], int n, int k) {
        
        if (m == 0)
            
            return B[k-1];
            
        if (n == 0)
            
            return A[k-1];

        if (k == 1)
            return min(A[0], B[0]);
        
        int d = k/2;

        d = min(m, d);
        d = min(n, d);

        if (A[d - 1] < B[d - 1]) {
            
            return findNumberKSortedArrays(A + d, m - d, B, n, k - d);
        }
        else 
            return findNumberKSortedArrays(A, m, B + d, n - d, k - d);
    }
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int total = m + n;

        if (total % 2) {
            return findNumberKSortedArrays(A, m, B, n, (total + 1)/2);
        }

        return (findNumberKSortedArrays(A, m, B, n, total/2) + findNumberKSortedArrays(A, m, B, n, total/2 + 1))/2.0;

    }
};