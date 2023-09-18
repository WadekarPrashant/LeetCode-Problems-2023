class Solution {
public:
    using int2=pair<int, int>;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        priority_queue<int2> pq;
        for(int i=0; i<k; i++){
            int ones=accumulate(mat[i].begin(), mat[i].end(), 0);
            pq.emplace(ones, i);
        }

        for(int i=k; i<n; i++){
            int ones=accumulate(mat[i].begin(), mat[i].end(), 0);
            int wt=pq.top().first;
            if (ones<wt){
                pq.emplace(ones, i);
                pq.pop();
            }
        }
    //    cout<<pq.size()<<endl;
        vector<int> ans(k, 0);
        for(int i=k-1; i>=0; i--){
            ans[i]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
