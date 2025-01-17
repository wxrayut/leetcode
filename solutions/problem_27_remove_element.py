

def remove_element(nums: list[int], value: int):

    k = 0
    
    for num in nums:
        if num == value:
            continue
        nums[k] = num
        k += 1

    return k

# Test cases.
nums = [
    ([3, 2, 2, 3], 3, 2), # Output: 2
    ([0, 1, 2, 2, 3, 0, 4, 2], 2, 5) # Output: 5
]

if __name__ == "__main__":

    for i, (n, value, expected_length) in enumerate(nums):
        k = remove_element(n, value)
        assert k == expected_length
        print("Case #%d: %d" % (i, k))
        # For the expected nums: n[:k]
