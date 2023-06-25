class Solution {
public:
    int countRoutes(vector<int>& locations, int s, int finish, int f) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int> (f + 1, 0));
        dp[finish][0] = 1;
        for (int fuel = 1; fuel <= f; fuel++)
        {
            for (int start = 0; start < n; start++)
            {
                int ans = 0, mod = 1e9 + 7;
                if (start == finish)
                {
                    ans++;
                }
                for (int i = 0; i < n; i++)
                {
                    int dis = abs(locations[i] - locations[start]);
                    if ((i != start) && (fuel >= dis))
                    { 
                        ans += dp[i][fuel - dis];
                        ans %= mod;
                    }
                }
                dp[start][fuel] = ans % mod;
            } 
        }
        return dp[s][f];
    }
};
