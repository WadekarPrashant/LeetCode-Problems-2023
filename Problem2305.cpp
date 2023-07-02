class Solution {
    unordered_map<int, int> maskCookieSum;
    int inf = 1e9;
    vector<vector<int>> cache;
    int doIt(vector<int>& cookies, int available, int k) {
        if (k == 0) {
            return available == 0? 0: inf;
        }
        auto& cachedAns = cache[available][k];
        if (cachedAns != -1)
            return cachedAns;
        int ans = inf;
        for (int submask = available; submask; submask = available & (submask - 1)) {
            ans = min(ans, max(maskCookieSum[submask], doIt(cookies, (available ^ submask), k - 1))); 
        }
        return cachedAns = ans;
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int available = (1 << 10) - 1;
        maskCookieSum = {};
        for (int mask = 0; mask <= available; ++mask) {
            int sum = 0;
            for (int position = 0; position < min(31, (int) cookies.size()); ++position) {
                if ((mask >> position) & 1) {
                    sum += cookies[position];
                }
            }
            maskCookieSum[mask] = sum;
        }
        cache.assign(available + 1, vector<int>(k + 1, -1));
        return doIt(cookies, available, k);
    }
};
