class Solution:
    def romanToInt(self, s: str) -> int:
        total = 0
        ignoredIndices = []
        mutators =  [["IV", 4], ["IX", 9], ["XL", 40], ["XC", 90], ["CD", 400], ["CM", 900]]

        for i in range(0, len(s)):
         if i - 1 > -1:
          for x in mutators:
           if s[i -1] + s[i] == x[0]: total += x[1]; ignoredIndices.append(i - 1); ignoredIndices.append(i)

        for i in range(0, len(s)):
         ignore = False
         for x in ignoredIndices:
          if i == x: ignore = True
         if not ignore:
          if s[i] == "I": total += 1
          if s[i] == "V": total += 5
          if s[i] == "X": total += 10
          if s[i] == "L": total += 50
          if s[i] == "C": total += 100
          if s[i] == "D": total += 500
          if s[i] == "M": total += 1000
        return total