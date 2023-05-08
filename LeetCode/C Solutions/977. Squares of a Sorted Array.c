int 
comparator(
    int* a, 
    int* b)
{
  return *a - *b;
}


int* 
sortedSquares(
    int* nums, 
    int numsSize, 
    int* returnSize)
{
    for (int i = 0; i < numsSize; ++i)
        nums[i] *= nums[i];
    
    qsort(nums, numsSize, sizeof(int), comparator);
    *returnSize = numsSize;
    return nums;
}