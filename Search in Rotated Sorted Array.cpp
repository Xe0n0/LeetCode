//1. index return by searching in subrange is invalid

class Solution {
private:
    int* searchPivot(int A[], int n) {
        
        if (n <= 0) return NULL;
        
        int mid = n/2;
        
        if (A[mid] >= A[0]) {
            if (mid + 1 < n) {
                if (A[mid+1] > A[0])
                    return searchPivot(A+mid+1, n-mid-1);
                else
                    return A+mid;
            }
            else
                return A+mid;
        }
        else {
            return searchPivot(A, mid);
        }
    }
public:
    int search(int A[], int n, int target) {
        
        if (n <= 0) return -1;
        
        int* p = searchPivot(A, n);
        
        pair<int *, int *> bounds;
        
        bounds = equal_range(A, p+1, target);
        
        if (bounds.first != bounds.second)
            return bounds.first - A;
        
        bounds = equal_range(p+1, A+n, target);
        
        if (bounds.first != bounds.second)
            return bounds.first - A;
        
        return -1;
    }
};