class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<int> dp(n, -1);
        return calculateMinCost(n - 1, colors, neededTime, dp, 'A', neededTime[n - 1]);
    }

    // Recursive function to calculate the minimum cost
    int calculateMinCost(int i, string& colorSequence, vector<int>& timeRequired, vector<int>& memo, char previousColor, int previousTime) {
        if (i < 0) {
            // Base case: Reached the beginning of the sequence
            return 0;
        }

        if (memo[i] != -1) {
            // If the sub-problem is solved earlier, return the stored result
            return memo[i];
        }

        if (colorSequence[i] == previousColor) {
            // If the current color is the same as the previous one, choose the minimum time
            return memo[i] = calculateMinCost(i - 1, colorSequence, timeRequired, memo, colorSequence[i], max(timeRequired[i], previousTime)) + min(timeRequired[i], previousTime);
        } else {
            // If the current color is different, choose the time required for the current color
            return memo[i] = calculateMinCost(i - 1, colorSequence, timeRequired, memo, colorSequence[i], timeRequired[i]);
        }
    }
};
