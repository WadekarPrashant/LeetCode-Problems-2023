class Solution(object):
    def maxNumEdgesToRemove(self, n, edges):
        
        # Union-Find Utilities
        def find(i, parent):
            if i != parent[i]:
                parent[i] = find(parent[i], parent)
            return parent[i]
        def unite(x, y, parent):
            x, y = find(x, parent), find(y, parent)
            if x == y: return 0
            parent[x] = y
            return 1
        ret = e1 = e2 = 0
        # Type-3 edges
        parent3 = range(n + 1)
        for t, i, j in edges:
            if t == 3:
                if unite(i, j, parent3):
                    e1 += 1
                    e2 += 1
                else:
                    ret += 1
                    
        # For each of Alice and Bob
        parent1 = parent3[:]
        parent2 = parent3[:]
        for t, i, j in edges:
            if t == 1: # Alice
                if unite(i, j, parent1):
                    e1 += 1
                else:
                    ret += 1
            elif t == 2: # Bob
                if unite(i, j, parent2):
                    e2 += 1
                else:
                    ret += 1
        
        return ret if e1 == e2 == n - 1 else -1