class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& S, vector<vector<string>>& P) {
        // bitmask stuff
        map<string, int> mp;
        int n = S.size(), m = P.size();
        for(int i=0; i<n; i++)
            mp[S[i]] = i;
        
        int MASK = 1 << n, INF = m;
        // dp
        vector<int> dp(MASK, INF), idx(MASK, -1), prv(MASK, -1);
        dp[0] = 0;
        for(int mask=0; mask<MASK; mask++) {
            for(int i=0; i<m; i++) {
                int mask2 = mask;
                for(auto x: P[i])
                    mask2 |= 1 << mp[x];

                int cur = dp[mask] + 1;
                if(cur < dp[mask2]) {
                    dp[mask2] = cur;
                    prv[mask2] = mask;
                    idx[mask2] = i;
                }
            }
        }

        vector<int> ans;
        for(int mask=MASK-1; mask>0; mask=prv[mask])
            ans.push_back(idx[mask]);
        return ans;
    }
};
