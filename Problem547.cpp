class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> seen(n, false);
        
        function<bool(int)> visit = [&](int u) {
            if (seen[u]) return false;
            seen[u] = true;
            vector<int> todo {u};
            while (!todo.empty()) {
                u = todo.back();
                todo.pop_back();
                for (int v = 0; v < n; v++) {
                    if (isConnected[u][v] && !seen[v]) {
                        seen[v] = true;
                        todo.push_back(v);
                    }
                }
            }
            return true;
        };
        
        int provinces = 0;
        for (int u = 0; u < n; u++) provinces += visit(u);
        return provinces;
    }
};
