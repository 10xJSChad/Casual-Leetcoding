#include <iostream>
#include <sstream>
#include <string> 
#include <vector>


class Solution {
public:
    
    std::vector<std::string> split(std::string s, char splitAt) {
        std::string word;
        std::vector<std::string> splitString;
        for (auto x : s) {
            if (x == splitAt) {
                if (word != "") { splitString.push_back(word); }
                word = "";
            }
            else { word += x; }
        }
        if (word != "") { splitString.push_back(word); }
        word = "";
        return splitString;
    }
    
    std::string reverse(std::string s) {
        std::string sReverse;
        for (int i = s.size() - 1; i > -1; i--) {
            sReverse += s[i];
        }
        return sReverse;
    }
    
    string reverseWords(string s) {
        std::string newString;
        std::vector<std::string> splitString = split(s, ' ');
        for (auto x : splitString) {
            newString += (reverse(x) + " ");
        }
        
        newString.pop_back();
        return newString;
    }
};