class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a = 0, b = x;
        
        if (x <= 1) return x;
        
        while (a < b - 1) {
            
            int mid = a + (b - a) /2;
            
            if (mid  < x / mid) {
                a = mid;
            }
            else if (mid > x / mid) {
                
                b = mid;
            }
            else return mid;
            
        }
        
        
        return a;
    }
};