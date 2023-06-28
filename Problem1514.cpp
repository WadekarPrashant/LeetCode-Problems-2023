class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> dist(n, 0.0);
        priority_queue<pair<double, int>> pq;
        vector<vector<pair<int, double>>> adj(n);
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        dist[start] = 1.0;
        pq.push({1.0, start});
        while (!pq.empty()) {
            double du = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (du != dist[u]) continue;
            for (auto [v, w]: adj[u]) {
                if (dist[v] < dist[u] * w) {
                    dist[v] = dist[u] * w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist[end];
    }
};
