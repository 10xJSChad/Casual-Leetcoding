class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        int sum = 0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int i=0;i<nums1.size();i++){
            sum+=nums1[i]*nums2[nums1.size()-i-1];
        }      
        return sum;
    }
};