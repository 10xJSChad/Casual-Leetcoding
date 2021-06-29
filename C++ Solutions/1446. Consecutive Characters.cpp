class Solution {
public:
    int maxPower(string s) {
        char current;
        int count = 0;
        int highest = 0;
        
        for (int i = 0; i < s.size(); i++){
            if (s[i] != current){
                if (count > highest) {highest = count;}
                count = 0;
                current = s[i];
                count++;
            }
            else {
                count++;
            }
        }
        if (count > highest) {highest = count;}
        return highest;
    }
};