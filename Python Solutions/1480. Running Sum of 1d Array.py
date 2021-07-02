class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        toAdd = 0
        for i in range(0, len(nums)):
            toAdd += nums[i]
            nums[i] = toAdd;
        return nums;