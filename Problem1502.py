class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort()
        prev = arr[0]
        curr = arr[1]
        diff = curr - prev
        prev = curr
        N = len(arr)
        
        for i in range(2, N):
            curr = arr[i]
            if curr - prev != diff:
                return False
            prev = curr
        return True
