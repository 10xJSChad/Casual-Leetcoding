int*
getConcatenation(
    int* nums, 
    int numsSize, 
    int* returnSize)
{
    nums = (int*) realloc(nums, ((numsSize * 2) * sizeof(int)));
    memmove(&nums[numsSize], &nums[0], numsSize * sizeof(int));
    
    *returnSize = numsSize * 2;
    return nums; 
}
