class Solution:
 def containsDuplicate(self, nums: List[int]) -> bool:
   hashmap = dict()
 
   for i in range(len(nums)):
   if nums[i] in hashmap.keys():
     return True
   else:
     hashmap[nums[i]] = i
 
   return False
