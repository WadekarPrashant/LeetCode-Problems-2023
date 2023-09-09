class Solution {
public:
    // Recursive function to count combinations
    int f(int n, vector<int>& nums, int target, vector<int>& dp) {

        // If the target is reached, return 1 (one valid combination found)
        if (target == 0) {
            return 1;
        }
        // If the target becomes negative, it's not a valid combination
        if (target < 0) {
            return 0;
        }
        // If the result for the current target is already calculated, return it
        if (dp[target] != -1) {
            return dp[target];
        }
        int take = 0;

        // Iterate through the numbers and try taking each one to reach the target
        for (int j = 0; j < n; ++j) {
            take += f(n, nums, target - nums[j], dp); // Recursively count combinations
        }

        // Store the result in the DP table and return it
        return dp[target] = take;
    }

    int combinationSum4(vector<int>& nums, int target) {

        vector<int>dp(target+1,-1);
       return f(nums.size(),nums,target,dp);


    }
};
