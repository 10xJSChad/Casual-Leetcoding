int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0;
    int highest = 0;
        
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] == 1) {count++;}
        else {
            if (count > highest) {highest = count;}
            count = 0;
        }
    }
    
    if (count > highest) {highest = count;}
    return highest;
}