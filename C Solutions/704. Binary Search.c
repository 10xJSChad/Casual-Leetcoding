int search(int* nums, int numsSize, int target){
    int min = 0, max = numsSize - 1;
    while(min <= max){
        int mid = (min + max) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) max = mid - 1;
        else min = mid + 1;
    } return -1;
}
