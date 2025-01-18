
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int search_insert(int nums[], int numsSize, int target) {
    
    int left = 0, right = numsSize - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}


int main() {
    // Test cases.
    int nums[] = {1, 3, 5, 6};
    int targets[] = {5, 2, 7};
    int expected_nums[] = {2, 1, 4};

    int size = sizeof(targets) / sizeof(targets[0]);
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < size; i++) {
        int match = search_insert(nums, numsSize, targets[i]);
        assert(match == expected_nums[i]);
        printf("Case #%d: %d\n", i, match);
    }

    return EXIT_SUCCESS;
}
