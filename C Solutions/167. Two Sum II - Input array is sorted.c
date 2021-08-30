//Good solution
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *output = (int *)malloc(sizeof(int) * 2);
    
    int left = 0;
    int right = numsSize -1;
    while(1){
        int sum = nums[left] + nums[right];
        if(sum == target){
            output[0] = left+1;
            output[1] = right+1;
            return output;
        }
        
        if(sum > target)
            right--;
        else
            left++;
    }
    return output;
}

//Bad, overcomplicated solution
int* twoSum(int* numbers, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *output = (int *)malloc(sizeof(int) * 2);
    int curr = 0;
    search:;
    int left = curr;
    int right = curr;
    while(1){
        if(left > -1 && numbers[left] + numbers[curr] < target)
            left = -1;
        else if(left > -1 && numbers[left] + numbers[curr] == target && left != curr){
            output[0] = left+1; output[1] = curr+1;
            return(output);
        }
        
        if(right < numsSize && numbers[right] + numbers[curr] > target)
            right = numsSize;
        else if(right < numsSize && numbers[right] + numbers[curr] == target && right != curr){
            output[0] = curr+1; output[1] = right+1;
            return(output);
        }
        
        left--; right++;
        if(left < 0 && right > numsSize-1){
            curr++; goto search;
        }
    }
    return output;
}
