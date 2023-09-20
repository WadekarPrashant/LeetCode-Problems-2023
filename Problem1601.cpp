class Solution {
    int doIt(int n, vector<vector<int>>& requests, int available, vector<int>& existingResidentCountInBuilding) {
        vector<int> newResidentCountInBuilding = existingResidentCountInBuilding;
        int requestCount = 0, requestLen = requests.size();
        for (int pos = 0; pos < 31; ++pos) {
            if ((available >> pos) & 1) {
                int idx = requestLen - 1 - pos;
                int from = requests[idx][0], to = requests[idx][1];
                --newResidentCountInBuilding[from];           
                ++newResidentCountInBuilding[to];
                ++requestCount;
            }
        }
        if (newResidentCountInBuilding == existingResidentCountInBuilding) {
            return requestCount;
        } else {
            return 0;
        }
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int maxRequests = 0;
        vector<int> residentCountInBuilding(n, 0);
        for (auto& request: requests) {
            residentCountInBuilding[request[0]]++;
        }
        for (int mask = 0; mask < (1 << ((int) requests.size())); ++mask) {
            maxRequests = max(maxRequests, doIt(n, requests, mask, residentCountInBuilding));
        }
        return maxRequests;
    }
};
