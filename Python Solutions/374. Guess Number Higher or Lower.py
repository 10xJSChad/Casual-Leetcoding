# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        min = 0
        max = n
        previous = None
        while True:
            if guess(n) == -1:
                max = n
            else:
                min = n
            n = int((min + max) / 2)
            if n == previous: return n
            previous = n
