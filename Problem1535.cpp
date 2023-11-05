class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        if (n<=k) return *max_element(arr.begin(), arr.end());
        int count=0, winner=arr[0];
        #pragma unroll
        for (int i=1; i<n && count<k; i++) {
            if (arr[i] > winner) {
                winner=arr[i];
                count=1;
            } 
            else 
                count++;
        }
        return winner;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
