class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        G = Counter()
        n=len(grid)
        res=0
        for i in grid:
            G[(tuple(i))]+=1
        for i in range(n):
            cur = []
            for j in range(n):
                cur.append(grid[j][i])
            if tuple(cur) in G:
                res += G[tuple(cur)]
        return res
