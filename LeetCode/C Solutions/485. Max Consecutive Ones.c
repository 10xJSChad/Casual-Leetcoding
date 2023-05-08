int 
findMaxConsecutiveOnes (
    int* nums, int numsSize)
{
    int max = 0;
    int curr = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) curr++;
        else curr = 0;
        
        if (curr > max) max = curr;
    }
    
    return max;
}
