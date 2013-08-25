class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        
        int r;
        int d = INT_MAX;
        
        for (int i = 0; i < num.size(); i++) {
            
            int j = i + 1;
            int k = num.size() - 1;
            
            while (j < k) {
                
                int temp = num[i] + num[j] + num[k];
                
                if (abs(temp - target) < d) {
                    d = abs(temp - target);
                    r = temp;
                }
                
                if (temp < target) {
                    
                    j++;
                    
                }
                else if (temp > target) {
                    k--;
                }
                else {
                    return target;
                }
                
            }
            
        }
        
        return r;
    }
};