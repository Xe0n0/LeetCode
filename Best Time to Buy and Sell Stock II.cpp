class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() == 0) return 0;
        
        
        int min_c, max_p;
        min_c = prices[0];
        max_p = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            
            min_c = min(min_c, prices[i]);
            
            if (i + 1 < prices.size() && prices[i] < prices[i+1]) continue;
            
            if (prices[i] - min_c > 0 ) {
                
                max_p += prices[i] - min_c;
                
                min_c = INT_MAX;
            }
        }
        
        return max_p;
    }
};