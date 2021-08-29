int* getConcatenation(int* nums, int numsSize, int* returnSize){
    int* ans=(int*)malloc(sizeof(int)*(2*numsSize));
    for(int i = 0; i<numsSize;i++){
        ans[i] = nums[i];
        ans[numsSize+i] = nums[i];
    }
    *returnSize = numsSize * 2;
    return ans; 
}
