class Solution {
public:
    //Bubble sort
    void sortColors(vector<int>& nums) {
        int temp;
        while(true){
            bool changed = false;
            for(int i=0; i<nums.size();i++){
                if(i > 0){
                    if(nums[i] < nums[i-1]){
                        temp = nums[i];
                        nums[i] = nums[i-1];
                        nums[i-1] = temp;
                        changed = true;
                    }
                }
            }
            if(!changed){break;}
        }
    }
};
