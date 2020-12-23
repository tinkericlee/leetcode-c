/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int* result = (int*) malloc(2 * sizeof(int));
    result[0] = 0;
    result[1] = 0;
    for (int i=0; i < numsSize; i++) {
        for (int j=i+1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
            }
        }
        if (result[0] != 0 && result[1] != 0) {
            break;
        }
    }

    return result;
}