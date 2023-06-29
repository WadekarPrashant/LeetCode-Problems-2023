class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        R, C = len(grid), len(grid[0])
        empty, wall, start = '.', '#', '@'
        # (row, col, key_mask)
        queue = deque([(r, c, 0) for r, c in product(range(R), range(C)) if grid[r][c] == start])
        steps = 0
        n = sum(1 for r, c in product(range(R), range(C)) if grid[r][c] in string.ascii_lowercase)
        end_mask = (1 << n) - 1
        in_bounds = lambda r, c: 0 <= r < R and 0 <= c < C
        neighborhood = lambda r, c: [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]
        vis = set(list(queue))
        while queue:
            for _ in range(len(queue)):
                r, c, mask = queue.popleft()
                if mask == end_mask: return steps
                for nr, nc in neighborhood(r, c):
                    if not in_bounds(nr, nc) or grid[nr][nc] == wall: continue
                    val = grid[nr][nc]
                    nmask = mask
                    # key condition
                    if val in string.ascii_lowercase:
                        key = string.ascii_lowercase.index(val)
                        nmask |= (1 << key)
                    # lock condition
                    if val in string.ascii_uppercase:
                        lock = string.ascii_uppercase.index(val)
                        have_key = (nmask >> lock) & 1
                        if not have_key: continue
                    nstate = (nr, nc, nmask)
                    if nstate in vis: continue
                    vis.add(nstate)
                    queue.append(nstate)
            steps += 1
        return -1
