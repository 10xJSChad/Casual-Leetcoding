class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int highestNum = 0;
        int removeAmount = 0;
        for (int x : nums){
            if (x > highestNum) {highestNum = x;}
        }
        for (int i=0;i<nums.size();i++){
            if (nums[i] == val) {
                nums[i]=highestNum+1;removeAmount++;
            }
        }
        sort(nums.begin(), nums.end()); 
        for (int i=0;i<removeAmount;i++){nums.pop_back();}
        return nums.size();
    }
};