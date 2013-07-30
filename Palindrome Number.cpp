//1. what if number end with zero?
//2. negative numbers? revert will overflow?
//3. no extra space? is single variable ok?

class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) return false;
        
        if (x == INT_MIN) return false;
        
        int n = 0;
        
        int t;
        
        for (t = 1; x/t >= 1; t *= 10, n++){
            if (x/t < 10) {
                n++;
                break;
            };
        };

        int m = 10;
        for (int i = 0; i < n/2; i++) {
            if ((x % m) / (m / 10) != x/t) return false;
            
            m *= 10;
            x %= t;
            t /= 10;
        }
        
        return true;
    }
};