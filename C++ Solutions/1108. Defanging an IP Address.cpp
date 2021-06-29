class Solution {
public:
    
    std::string replace(std::string s, char toReplace, std::string replaceWith) {
        std::string newString;
        for (auto x : s) {
            if (x == toReplace) { newString += replaceWith; }
            else { newString += x; }
        }
        return newString;
    }
    
    string defangIPaddr(string address) {
        address = replace(address, '.', "[.]");
        return address;
    }
};