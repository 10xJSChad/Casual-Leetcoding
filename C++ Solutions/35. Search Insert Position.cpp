class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int current = 0;
        if(nums[nums.size() - 1] < target) {return(nums.size());}
        if(nums[nums.size() - 1] == target) {return(nums.size() - 1);}
        while(current < nums.size() - 1){
            if(nums[current] == target){return(current);}
            if(nums[current] < target && nums[current + 1] > target){
                return(current + 1);
            }
            current++;
        }
        return(0);
    }
};
