#include <vector>
#include <bitset>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
  int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    
    vector<vector<int>> graph (n); // node
    for (int bomb1 = 0; bomb1 < n; bomb1++) {
      long x1 = bombs[bomb1][0], y1 = bombs[bomb1][1], r1 = bombs[bomb1][2];
      for (int bomb2 = 0; bomb2 < n; bomb2++) {
        long x2 = bombs[bomb2][0], y2 = bombs[bomb2][1];
        if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= r1 * r1)
          graph[bomb1].emplace_back(bomb2);
      }
    }
    
    int maxDetonation = 0;
    for (int bomb = 0; bomb < n; bomb++) {
      maxDetonation = max(maxDetonation, detonate(graph, bomb, bitset<100>() = {}));
    }
    
    return maxDetonation;
  }
  
private:
  int detonate(vector<vector<int>>& graph, int bomb, bitset<100>& detonated) {
    if (detonated[bomb])
      return 0;
    
    detonated[bomb] = 1;
    
    for (const int& neighbor : graph[bomb]) {
      detonate(graph, neighbor, detonated);
    }
    
    return detonated.count();
  }
};
