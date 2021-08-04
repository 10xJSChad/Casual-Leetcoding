class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        highest, nextHighest = 0, 0
        original = nums
        nums = sorted(nums)
        if len(nums) == 1: return 0
        for x in nums:
            if x > highest: nextHighest = highest; highest = x
        if highest >= nextHighest * 2:
            return(original.index(highest))
        return -1
