class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
    
        res = []
        i = j = 0
        n = len(nums)

        while i < n:
            while j+1 < n and nums[j] == nums[j+1]-1:
                j += 1

            if j-i+1 == 1:
                res.append(str(nums[i]))
                j += 1
                i = j 
            else:
                res.append(str(nums[i]) + "->" + str(nums[j]))
                j += 1
                i = j
        
        return res