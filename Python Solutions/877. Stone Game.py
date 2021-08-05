class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        current = 0; pilesTotal = sum(piles)
        while len(piles) > 0:
            current += max(piles); piles.pop(piles.index(max(piles)))
            piles.pop(piles.index(max(piles)))
        return current > pilesTotal / 2
