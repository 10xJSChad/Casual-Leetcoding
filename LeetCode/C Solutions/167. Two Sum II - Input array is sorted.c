int* 
twoSum(
    int* nums,
    int numsSize,
    int target,
    int* returnSize)
{
    int* output = (int*) malloc(2 * sizeof(int)); 
    int left = 0;
    int right = numsSize - 1;

    while (true) {
        int sum = nums[left] + nums[right];
        
        if (sum == target) {
            output[0] = ++left;
            output[1] = ++right;

            *returnSize = 2;
            return output;
        }
        
        if (sum > target)
            --right;
        else
            ++left;
    }

    return 0;
}
