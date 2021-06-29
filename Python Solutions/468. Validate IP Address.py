class Solution:
    def validIPAddress(self, IP: str) -> str:
     #Quick Filter
     if IP.find(".") != -1: ipList = IP.split(".")
     else: ipList = IP.split(":")
     for ipListSplit in ipList: 
      if len(ipListSplit) > 4: return("Neither")
      if len(ipListSplit) < 1: return("Neither")

     #IPv4
     toReturn = ""
     IPv4Valid = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
     ipList = IP.split(".")
     if len(ipList) != 4: toReturn = "Neither"
     for ipListSplit in ipList:
      numOnly = True
      if len(ipListSplit) > 3: toReturn = "Neither"
      if len(ipListSplit) > 1:
       if ipListSplit[0] == "0": toReturn = "Neither"
      for individualNumber in ipListSplit:
       isNumber = False
       for validNumber in IPv4Valid: 
        if individualNumber == validNumber: isNumber = True
       if not isNumber: numOnly = False; toReturn = "Neither"
      if numOnly: 
       if int(ipListSplit) > 255: toReturn = "Neither"
     if toReturn == "": return("IPv4")

     #IPv6
     toReturn = ""
     IPv6Valid = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"]
     ipList = IP.split(":")
     if len(ipList) != 8: toReturn = "Neither"
     for ipListSplit in ipList:
      if len(ipListSplit) > 4: toReturn = "Neither"
      if len(ipListSplit) < 1: toReturn = "Neither" 
      for individualCharacter in ipListSplit:
       isValid = False
       for validCharacter in IPv6Valid: 
        if individualCharacter.lower() == validCharacter.lower(): isValid = True
       if not isValid: toReturn = "Neither"
     if toReturn == "": return("IPv6")
     return toReturn