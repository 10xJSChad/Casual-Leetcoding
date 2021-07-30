# The isBadVersion API is already defined for you.
# @param version, an integer
# @return an integer
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        min = 0
        max = n
        previous = None
        while True:
            if isBadVersion(n):
                max = n
            else:
                min = n
            n = int((min + max) / 2)
            if n == previous: return n + 1
            previous = n
