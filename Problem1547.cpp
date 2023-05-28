class Solution {
public:

    int dp[109][109];
    int solve(int l, int r, int i, int j, vector<int>&cuts) {
            if(l>=r) return 0;
            if(i>j) return 0;
            if(i==j) return r-l;
            if(dp[i][j]!=-1) return dp[i][j];
            int res = INT_MAX;
            for(int k=i; k<=j ;k++) {
                long int curr_res = r-l + solve(l, cuts[k], i, k-1, cuts) + solve(cuts[k],r, k+1, j, cuts);
                res = min(res, (int)curr_res);
            }
            return dp[i][j]=res;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        memset(dp,-1, sizeof(dp));
        return solve(0, n, 0, cuts.size()-1, cuts);
        
    }
};
