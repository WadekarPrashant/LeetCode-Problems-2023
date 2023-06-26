class Solution {
public:
    long long totalCost(vector<int>& costs, int K, int candidates) {
        int n = costs.size();
        int i = candidates - 1, j = n - candidates;
        priority_queue<pair<int, bool>, vector<pair<int, bool>>, greater<pair<int, bool>>> pq;
        for (int k = 0; k < candidates; k++)
        {
            pq.push({costs[k], 0});
        }
        if (j <= i)
        {
            j = candidates;
        }
        for (int k = j; k < n; k++)
        {
            pq.push({costs[k], 1});
        }
        long long ans = 0;
        for (int k = 0; k < K; k++)
        {
            ans += pq.top().first;
            bool flag = pq.top().second;
            pq.pop();
            if (flag)
            {
                if (j > i + 1)
                {
                    j--;
                    pq.push({costs[j], 1});
                }
            }
            else
            {
                if (i + 1 < j)
                {
                    i++;
                    pq.push({costs[i], 0});
                }
            }
        }
        return ans;
    }
};
