class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> buy(n+1), sell(n+1); //Maximum profits when buy/sell on the ith day
        buy[0] = -prices[0];
        for (int i = 1; i <= n; i++) {
            buy[i] = max(buy[i-1], sell[i-1] - prices[i-1]);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i-1] - fee);
        }
        return sell[n];
    }
};
