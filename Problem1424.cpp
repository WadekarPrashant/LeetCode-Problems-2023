class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size(), maxSum = 0, size = 0, index = 0;
        std::vector<std::vector<int>> map(100001);
        
        for (int i = 0; i < m; i++) {
            size += nums[i].size();
            for (int j = 0; j < nums[i].size(); j++) {
                int sum = i + j;
                map[sum].push_back(nums[i][j]);
                maxSum = std::max(maxSum, sum);
            }
        }
        
        std::vector<int> res(size);
        for (int i = 0; i <= maxSum; i++) {
            std::vector<int>& cur = map[i];
            for (int j = cur.size() - 1; j >= 0; j--) {
                res[index++] = cur[j];
            }
        }
        
        return res;
    }
};
