class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        sol=low=0
        for row in grid:
            row.reverse()
            ind = bisect_right(row,-1,low)
            low = max(0,ind-1)
            sol+=ind
        return sol
