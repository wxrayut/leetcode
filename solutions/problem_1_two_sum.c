
#include <stdio.h>
#include <stdlib.h>


int *twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int *result = (int *)malloc(sizeof(2 * sizeof(int)));
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}


int main() {
    // Test cases.
    int targets[6] = {9, 6, 6, 10, 5, 8};
    int nums[6][4] = {
        {2, 7, 11, 15},
        {3, 2, 4},
        {3, 3},
        {1, 9, 4, 5},
        {2, 1, 3, 4},
        {5, 3, 6, 2}
    };

    int size = sizeof(targets) / sizeof(targets[0]);

    for (int i = 0; i < size; i++) {

        int target = targets[i];
        int numsSize = sizeof(nums[i]) / sizeof(nums[i][0]);
        int returnSize = 0;
        int *result = twoSum(nums[i], numsSize, target, &returnSize);        

        printf("Case #%d: ", i);
        if (result) {
            for (int j = 0; j < returnSize; j++) {
                printf("%d ", result[j]);
            }
            free(result);
            printf("\n");
        } else {
            printf("No found indices for target: %d\n", target);
        }
    }

    return EXIT_SUCCESS;
}
