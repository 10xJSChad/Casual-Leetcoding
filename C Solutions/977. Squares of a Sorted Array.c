int* sortedSquares(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    
    for(int i = 0; i<numsSize; i++){
        nums[i] *= nums[i];
    }
    
    bool flag = true;
    while(flag){
        flag = false;
        for(int i = 0; i<numsSize; i++){
            if(i > 0 && nums[i] < nums[i-1]){
                int temp = nums[i];
                nums[i] = nums[i-1]; nums[i-1] = temp;
                flag = true;
            }
        }
    }
    return nums;
}
