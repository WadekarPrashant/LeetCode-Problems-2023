class Solution {
public:
    bool check(int n, int idx, long long maxSum, long long mx)
    {
        long long sum = 0;
        long long x = n - idx;
        if (x >= mx)
        {
            sum += mx*(mx + 1)/2;
            sum += x - mx;
        }
        else
        {
            long long y = mx - x;
            sum += mx*(mx + 1)/2 - y*(y + 1)/2;
        }
        x = idx;
        mx--;
        if (x >= mx)
        {
            sum += mx*(mx + 1)/2;
            sum += x - mx;
        }
        else
        {
            long long y = mx - x;
            sum += mx*(mx + 1)/2 - y*(y + 1)/2;
        }
        return sum <= maxSum;
    }
    int maxValue(int n, int index, int maxSum) {
        int lo = 1, hi = maxSum, mid, ans;
        while (lo <= hi)
        {
            mid = lo + (hi - lo)/2;
            if (check(n, index, maxSum, mid))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
