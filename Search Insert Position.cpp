class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        pair<int *, int *> bounds;
        
        bounds = equal_range(A, A+n, target);
        
        return bounds.first - A;
    }
};