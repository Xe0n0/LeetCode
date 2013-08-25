class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> subs;
        
        int maxArea = 0;
        
        for (int i = 0; i < height.size(); i++) {
            
            if (subs.empty() || height[i] >= height[subs.top()]) {
                
                subs.push(i);
                
            }
            else {
                    
                int idx = i;
                    
                while (!subs.empty() && height[subs.top()] >= height[i]) {
                        
                    idx = subs.top();
                        
                    subs.pop();
                        
                    if (subs.empty())
                        maxArea = max(maxArea, i * height[idx]);
                    else
                        maxArea = max(maxArea, (i - subs.top() - 1) * height[idx]);
                        
                }
                
                subs.push(i);
                    
               
            }
            
        }
        
        int end = height.size();
        
        while (!subs.empty()) {
            int idx = subs.top();
            
            subs.pop();
            
            if (subs.empty())
                maxArea = max(maxArea, end * height[idx]);
            else
                maxArea = max(maxArea, (end - subs.top() - 1) * height[idx]);
            
            
        }
        
        return maxArea;
    }
};