class Solution:
    def sortSentence(self, s: str) -> str:
        dict = {}; newStr = ""
        for x in s.split(" "):
            dict.update({int(x[-1]): x[:-1]})
        for i in range(1, len(dict) + 1):
            newStr += dict.get(i) + " "
        return newStr.strip()
