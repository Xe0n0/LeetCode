class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxA = 0;
        
        int i = 0;
        int j = height.size() - 1;
        
        while (i < j) {
            
            maxA = max(maxA, (j-i) * min(height[i], height[j]));
            
            if (height[i] < height[j]) {
                
                i++;
                
            }
            else
                j--;
        }
        
        return maxA;
    }
};