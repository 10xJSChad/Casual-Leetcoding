//I choose to solve this by converting the integer to a string because...
//Why wouldn't I?
//Could not find a single reason to *not* do it, so I did it.

#include <iostream>
#include <sstream>
#include <string> 

class Solution {
public:
    std::string toString(int i) {
        std::string s;
        std::stringstream ss;
        ss << i;
        ss >> s;
        return s;
    }
    
    bool isPalindrome(int x) {
        if (x < 0) {return false;}
        std::string s = toString(x);
        std::string sReverse;
        
        for (int i = s.size() - 1; i > -1; i--) {
            sReverse += s[i]; 
        }

        return sReverse == s;
    }
};