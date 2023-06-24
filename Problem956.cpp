class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size(), sum = 0;
        for (int i = 0; i < n; i++)
        sum += rods[i];
        vector<vector<int>> dp(2, vector<int> (2*sum + 1, -1e4));
        dp[n%2][sum] = 0;
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int diff = 0; diff <= 2*sum; diff++)
            {
                dp[idx%2][diff] = dp[!(idx%2)][diff];
                if (diff + rods[idx] <= 2*sum)
                {
                    dp[idx%2][diff] = max(dp[idx%2][diff], rods[idx] + dp[!(idx%2)][diff + rods[idx]]);
                }
                if (diff - rods[idx] >= 0)
                {
                    dp[idx%2][diff] = max(dp[idx%2][diff], dp[!(idx%2)][diff - rods[idx]]);
                }
            }
        }
        return dp[0][sum];
    }
};
