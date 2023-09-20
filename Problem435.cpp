class Solution {
public:
    static bool custom_sort(const vector<int>& v1, const vector<int>& v2){
        return v1[1] < v2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sorting + greedy?
        int ans = 0, curr_min = 0;
        int prev_b = INT_MIN;
        sort(intervals.begin(), intervals.end(), custom_sort);
        for (auto vec : intervals){
            int a = vec[0], b = vec[1];
            if (a < prev_b){
                ans+= 1;
                continue;
            }
            prev_b = b;
        }
        return ans;
    }
};
