class Solution {
public:
    int integerBreak(int n) {
        if (n<=3) return n-1;
        auto [k, r]=div(n, 3);
        if (r==1)
        {
            r=4, k--;
        }
        int ans=pow(3, k);
        if (r>0) ans*=r;
        return ans;
    }
};
