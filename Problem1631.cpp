class Solution {
public:
    using int2=array<int, 2>;
    int n, m;
    int to1D(int i, int j){
        return i*m+j;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        n=heights.size(), m=heights[0].size();
        if (n==1 && m==1) return 0;// edge case
        vector<int> dist(n*m, INT_MAX);
        vector<bool> visited(n*m, 0);
        priority_queue<int2, vector<int2>, greater<int2>> pq;
        pq.push({0, 0});// (dist, to1D(i, j))

        while (!pq.empty()) {
            auto [d, idx] = pq.top();
            auto [i, j]=div(idx, m);
            pq.pop();
            if (d>dist[idx]) continue;
            if (i==n-1 && j==m-1) return d;
            visited[idx]=1;
            int d2;
            if (i>0) {
                int w=abs(heights[i][j]-heights[i-1][j]);
                d2=max(d, w);
                int idx2=to1D(i-1, j);
                if (d2 < dist[idx2] && !visited[idx2]) {
                    dist[idx2] = d2;
                    pq.push({d2, idx2});
                }
            }
            if (i<n-1) {
                int w=abs(heights[i][j]-heights[i+1][j]);
                d2=max(d, w);
                int idx2=to1D(i+1, j);
                if (d2 < dist[idx2] && !visited[idx2]) {
                    dist[idx2] = d2;
                    pq.push({d2, idx2});
                }
            }
            if (j>0) {
                int w=abs(heights[i][j]-heights[i][j-1]);
                d2=max(d, w);
                int idx2=to1D(i, j-1);
                if (d2 < dist[idx2] && !visited[idx2]) {
                    dist[idx2] = d2;
                    pq.push({d2, idx2});
                }
            }
            if (j<m-1) {
                int w=abs(heights[i][j]-heights[i][j+1]);
                d2=max(d, w);
                int idx2=to1D(i, j+1);
                if (d2 < dist[idx2] && !visited[idx2]) {
                    dist[idx2] = d2;
                    pq.push({d2, idx2});
                }
            }

        }
        return 0;
    }
};
