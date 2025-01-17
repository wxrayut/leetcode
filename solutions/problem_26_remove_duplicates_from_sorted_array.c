
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int removeDuplicates(int* nums, int numsSize) {
    
    if (numsSize <= 1) {
        return numsSize;
    }

    int expectedNum = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] != nums[i]) {
            nums[expectedNum] = nums[i];
            expectedNum++;
        }
    }

    return expectedNum;
}


int main() {
    // Test cases.
    int nums[][10] = {
        {0, 1, 1, 2, 2, 2, 3, 4, 4, 4}, 
        {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}
    };
    // The expected answer with correct length.
    int expectedNums[2] = {5, 5};

    int size = sizeof(nums) / sizeof(nums[0]);
    
    for (int i = 0; i < size; i++) {

        int numsSize = sizeof(nums[i]) / sizeof(nums[i][0]);
        int k = removeDuplicates(nums[i], numsSize);

        printf("Case #%d: %d\n", i, k == expectedNums[i] ? 1 : 0);
    }

    return EXIT_SUCCESS;
}
