class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 1;
        
        if (x == 1) return 1;

        if (x == 0 or n < 0 and n == INT_MIN) return 0;

        if (n < 0) return 1.0 / pow(x, -n);
        
        double r = pow(x, n/2);
        
        if (n % 2) {
            
            return r * r * x;
            
        }
        
        return r * r;
    }
};