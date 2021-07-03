class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=n-1;i>-1;i--){
            nums1[nums1.size()-i-1] = nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }
};