class Solution {
public:
    vector<int> toReturn;
    int removeDuplicates(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            bool add = true;
                for(int j=0;j<toReturn.size();j++){
                    if(nums[i]==toReturn[j]){
                        add = false; break;
                    }
                }
            if(add){toReturn.push_back(nums[i]);}
            }
        nums = toReturn;
        return(toReturn.size());
        }
};