class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n = nums1.size(), m = nums2.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int s = min(n, k);
        for (int i = 0; i < s; i++)
        {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }
        while (!pq.empty())
        {
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            k--;
            if (!k)
            return ans;
            if (j != m - 1)
            {
                j++;
                pq.push({nums1[i] + nums2[j], {i, j}});
            }
        }
        return ans;
    }
};
