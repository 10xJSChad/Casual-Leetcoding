class Solution {
public:
    string removeVowels(string s) {
        string vowels = "aeiou";
        string newString;
        for(auto x:s){
            bool isVowel = false;
            for(auto y:vowels){
                if(tolower(x)==y){isVowel = true;}
            }
            if(!isVowel){newString+=x;}
        }
        return newString;
    }
};