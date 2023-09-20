class Solution {
    public int longestArithSeqLength(int[] nums) {
        int n = nums.length;
        int mx = Arrays.stream(nums).max().orElse(0);
        int[][] dp = new int[n][mx + mx + 5];

        int ans = 0;
        for (int r = 0; r < n; r++){
            for (int l = 0; l < r; l++){
                int d = nums[l] - nums[r];
                dp[r][d + mx] = 1 + dp[l][d + mx];
                ans = Math.max(dp[r][d + mx], ans);
            }
        }
        return ans + 1;
    }
}
