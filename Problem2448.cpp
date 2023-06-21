class Solution:
    def minCost(self, nums: List[int], cost: List[int]) -> int:
        cost_counter = Counter()
        for x, y in zip(nums, cost):
            cost_counter[x] += y
        prev = min(nums)
        prefix, suffix = 0, sum((x - prev) * y for x, y in cost_counter.items())
        prefix_delta, suffix_delta = 0, sum(cost)
        res = prefix + suffix
        for num in sorted(cost_counter.keys()):
            delta = num - prev
            prefix += delta * prefix_delta
            suffix -= delta * suffix_delta
            prefix_delta += cost_counter[num]
            suffix_delta -= cost_counter[num]
            prev = num
            res = min(res, prefix + suffix)
        return res
