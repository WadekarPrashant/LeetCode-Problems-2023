class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        MOD = 10**9+7
        n = len(nums)
        
        fact = [1]*(n+1)
        for i in range(1, n+1):
            fact[i] = (i*fact[i-1]) % MOD
            
        def modinv(x):
            return pow(x, MOD-2, MOD) # recall Fermat's little theorem
        
        def choose(n, k):
            return (((fact[n] * modinv(fact[n-k])) % MOD) * modinv(fact[k])) % MOD
            # return fact[n] // (fact[n-k]*fact[k])
        
        def go(nums):
            if len(nums) <= 1:
                return 1
            
            pivot = nums[0]
            smaller = [x for x in nums if x < pivot]
            greater = [x for x in nums if x > pivot]
            ans = choose(len(smaller) + len(greater), len(smaller)) % MOD
            ans = (ans * go(smaller)) % MOD
            ans = (ans * go(greater)) % MOD
            return ans
        
        return go(nums) - 1
