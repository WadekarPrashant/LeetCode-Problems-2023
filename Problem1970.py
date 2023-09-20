class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        def dfs(r,c):
            if r < 0 or r >= row or c < 0 or c >= col or (r,c) in vis or grid[r][c] == 1:
                return False
            if r == row - 1:
                return True
            
            ok = False
            vis.add((r,c))
            for dr, dc in [(0,1),(0,-1),(1,0),(-1,0)]:
                nr = r + dr
                nc = c + dc
                ok |= dfs(nr,nc)
            return ok
        
        lo = 1
        hi = row * col
        while lo != hi:
            m = (lo + hi + 1) >>1
            grid = [[0] * col for _ in range(row)]
            for r, c in cells[:m]:
                r -= 1
                c -= 1
                grid[r][c] = 1
            ok = False
            vis = set()
            for c in range(col):
                if grid[0][c] == 0 and dfs(0,c):
                    ok = True
            if ok: lo = m
            else: hi = m - 1
        return lo
