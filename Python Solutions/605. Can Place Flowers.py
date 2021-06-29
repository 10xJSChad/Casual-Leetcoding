class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
     ignoredIndices = []
     valid = False
     valids = 0
     for i in range(0, len(flowerbed)):
      ignore = False
      for x in ignoredIndices:
       if x == i: ignore = True
        
      if flowerbed[i] == 0 and not ignore:
       valid = True
    
       if i - 1 >= 0:
        if flowerbed[i - 1] == 1: valid = False
       if i + 1 < len(flowerbed):
        if flowerbed[i + 1] == 1: valid = False 
            
       if valid: 
        valids += 1
        if i - 1 > 0: ignoredIndices.append(i - 1)
        if i + 1 < len(flowerbed): ignoredIndices.append(i + 1)
     return(valids >= n)