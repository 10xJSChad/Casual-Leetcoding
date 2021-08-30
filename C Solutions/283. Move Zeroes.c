void moveZeroes(int* nums, int numsSize){
    int size = 0;
    for(int i = 0; i<numsSize;i++){
        if(nums[i] == 0){
            size++;
        }else if(size > 0){
            nums[i-size] = nums[i];
            nums[i] = 0;
        }
    }
}
