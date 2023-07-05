class Solution {
public:
    int longestSubarray(vector<int>& A) {
        int n = A.size();
        vector<int> L(n), R(n+1);
        for(int i=0; i<n; i++)
            if(A[i])
                L[i] = (i ? L[i-1] : 0) + 1;
        for(int i=n-1; i>=0; i--)
            if(A[i])
                R[i] = R[i+1] + 1;

        int ans = R[0] - 1;
        for(int i=1; i<n; i++)
            ans = max(ans, L[i-1] + R[i+1]);
        return ans;
    }
};
