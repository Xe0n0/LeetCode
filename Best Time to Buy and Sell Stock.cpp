// merge loop
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
            max_p = max(prices[i] - min_c, max_p);
        }
        
        return max_p;
    }
};