class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0])
        mod= 10**9+7
        @cache
        def f(i,j):
            cnt=0
            for di,dj in [(1,0),(0,1),(-1,0),(0,-1)]:
                ni,nj=i+di,j+dj
                if 0<=ni<m and 0<=nj<n and grid[i][j]<grid[ni][nj]:
                    cnt+=1+f(ni,nj)%mod
            return cnt%mod
        ans = m*n%mod
        for i in range(m):
            for j in range(n):
                ans+=f(i,j)%mod
        return ans%mod
