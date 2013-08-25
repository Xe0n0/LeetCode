// what if divisor is zero
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (divisor == 0 || dividend == 0) return 0;
        
        bool revert = false;
        bool need_recursive = false;
        
        if (dividend > 0) {
            revert = !revert;
            dividend = -dividend;
            need_recursive = true;
        }
        
        if (divisor > 0) {
            revert = !revert;
            divisor = -divisor;
            need_recursive = true;
        }
        
        if (need_recursive) {
            if (revert)
                return -divide(dividend, divisor);
            return divide(dividend, divisor);
        }
        
        //if (dividend < 0 && divisor > 0) return -divide(dividend, -divisor);
        //if (dividend > 0 && divisor < 0) return -divide(-dividend, divisor);
        //if (dividend > 0 && divisor > 0) return divide(-dividend, -divisor);
        
        int r = 0;
        int b = 1;
        int t = divisor;
        int temp = t;
        
        while (1) {
            
            temp = temp << 1;
            
            if (temp < t && temp > dividend) {
                t = temp;
                b = b << 1;
            }
            else break;
        }
        
        while (dividend < 0) {
            
            if (dividend - t <= 0) {
                dividend -= t;
                r += b;
            }
            else if (t == divisor) break;
            
            else {
                t = t >> 1;
                b >>= 1;
            }
        }
        
        
        return r;
    }
};