
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ans = 0;
        vector<int> arr(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            arr[i] = arr[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            arr[i] = max(arr[i], arr[i + 1] + 1);
            ans += arr[i];
        }
        return ans + arr[n - 1];
    }
};
