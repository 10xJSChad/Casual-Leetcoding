def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
    current = 0; highest = 0
    for x in nums:
        if x == 1: current += 1
        else: 
            if highest < current: highest = current
            current = 0    
    if highest < current: highest = current
    return highest