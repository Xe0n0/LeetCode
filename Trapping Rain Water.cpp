class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 3) return 0;
        
        int i = 0;
        vector<int> maxLeftBar(n, 0);
        int max_left = 0;
        
        while (i < n) {
            
            maxLeftBar[i] = max_left;
            max_left = max(max_left, A[i++]);
        }
        
        int max_right = 0;
        int total_rain = 0;
        i = n - 1;
        
        while (i >= 0) {
            
            int bar = min(max_right, maxLeftBar[i]);
            if (bar > A[i]) {
                total_rain += (bar-A[i]);
            }
            max_right = max(max_right, A[i]);
            i--;
        }
        
        return total_rain;
    }
};