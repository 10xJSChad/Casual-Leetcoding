class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        current = 0
        while len(piles) > 0:
            current += max(piles); piles.pop(piles.index(max(piles)))
            piles.pop(piles.index(max(piles)))
        return current > sum(piles) / 2
