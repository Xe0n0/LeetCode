class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() == 0) return 0;
        
        vector<int> profitBefore(prices.size(), 0);
        
        int lowest = prices[0];
        int highest = prices[0];
        
        for (int i = 1; i < prices.size(); i++) {
            
            lowest = min(lowest, prices[i]);
            profitBefore[i] = max(prices[i] - lowest, profitBefore[i-1]);
        }
        
        vector<int> profitAfter(prices.size() + 1, 0);
        
        lowest = prices[prices.size() - 1];
        highest= prices[prices.size() - 1];
        
        for (int i = prices.size() - 2; i >= 0; i--) {
            
            highest = max(highest, prices[i]);
            profitAfter[i] = max(highest - prices[i], profitAfter[i+1]);
            
        }
        
        int max_profit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            
            max_profit = max(max_profit, profitBefore[i] + profitAfter[i+1]);
            
        }
        
        return max_profit;
    }
};