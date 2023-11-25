class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sz = nums.size();
        vector<int> result(sz);
        vector<long long> prefSum(sz);
        for(int indx = 0; indx < sz; indx++){
            if(indx == 0)prefSum[indx] = nums[indx];
            else prefSum[indx] = prefSum[indx-1] + nums[indx]; 
        }
        for(int indx = 0; indx < sz; indx++){
             int currNum = nums[indx];
             int leftSum = currNum * (indx+1) - prefSum[indx];
             int rightSum = (prefSum[sz - 1] - prefSum[indx] - (sz - 1 - indx)  * currNum);
             result[indx] = leftSum + rightSum;
        }
        return result;
    }
};
