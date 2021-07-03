class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size()-1 == 0){
            if(digits[digits.size()-1] == 9){digits[digits.size()-1] = 1; digits.push_back(0);} 
            else{digits[ digits.size()-1]++;}
            return digits;
        } else
        if(digits[digits.size()-1] == 9){
            digits[digits.size()-1] = 0;
            for(int i= digits.size()-1-1;i>-1;i--){
                if(digits[i] != 9){
                    digits[i]++; break;
                } else{         
                    if(i == 0){
                        if(digits[i] == 9){
                            digits[i] = 1; digits.push_back(0); break;
                        }
                    }
                    digits[i] = 0;
                    if(digits[i-1] != 9){
                        digits[i-1]++; break;
                    }
                }
            }
            return digits;
        }
        digits[digits.size()-1]++;
        return digits;
    }
};

