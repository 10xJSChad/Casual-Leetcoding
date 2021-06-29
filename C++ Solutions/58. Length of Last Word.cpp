class Solution {
public:
    //Technically I could have just gone backwards and just read *one* word for convenience
    //But honestly I'm not much into the "competitive programming" approach and figured this could have more uses
    //as it can be easily converted to a general "string split" function
    
    int getLastWord(string s){
        string word;
        string previousWord;
        
        for (auto x : s ){
            if (x == ' '){
                if (word != "") { previousWord = word; }
                word = "";
            } else { word += x; }
        }
        
        if (word == "") {return previousWord.size();}
        return word.size();
        
    }
    
    int lengthOfLastWord(string s) {
        return getLastWord(s);
    }
};