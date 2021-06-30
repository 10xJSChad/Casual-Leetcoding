class Solution {
public:

    int firstUniqChar(string s) {
        //Honestly I didn't come up with this solution
        //I had a few other solutions that would have worked if it weren't for the time limit
        //This soltuion is by manaskarlekar4, I did not add anything to it.
        
        for (int i = 0; i < s.length(); i++){
            bool flag = true;
            for (int j = 0; j < s.length(); j++){
                if (i != j && s[i] == s[j]){
                    flag = false;
                    break;
                }
            }
            if(flag == true){return i;}
        }
        return -1;
    }
};