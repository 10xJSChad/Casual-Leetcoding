class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
     sortedList = []
     for x in A: sortedList.append(x * x)
     sortedList.sort()
     return(sortedList)