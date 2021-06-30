//Disgusting solution
//Not proud of it.

class Solution {
public:
    std::vector<int> reverse(std::vector<int> v, int a = -5000, bool fromRight = false) {
        if (a == -5000) {
            a = v.size() - 1;
            for (int i = 0; i < v.size() / 2; i++) {
                int temp = v[a]; v[a] = v[i]; v[i] = temp; a--;
            }
            return v;
        }
        else {
            if (!fromRight) {
                a--; int max = a / 2; if (a == 2) { max = a; }
                for (int i = 0; i < a; i++) {
                    int temp = v[a]; v[a] = v[i]; v[i] = temp; a--;
                }
                return v;
            }
            else {
                a--; int max = v.size() - 1;
                for (int i = max - a; i < max; i++) {
                    int temp = v[max]; v[max] = v[i]; v[i] = temp; max--;
                }
                return v;
            }
        }
        return v;
    }
    
    void rotate(vector<int>& nums, int k) { 
        if (nums.size() == 1){ return; }
        
        if(nums.size() < 5000){
            for(int i=0;i<k;i++){
                int lastNum = nums[nums.size() -1];
                for(int j=nums.size()-1;j>0;j--){
                    nums[j]=nums[j-1];
                }
                nums[0] = lastNum;
          }   
          return;
        }

        if (k > 0){
            nums = reverse(nums);
            nums = reverse(nums, k);
            nums = reverse(nums, nums.size() - k, true);      
        }
    }
};