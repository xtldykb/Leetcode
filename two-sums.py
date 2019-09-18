def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    for n in range(len(nums) - 1):
        if nums[n] > target:
            continue
        rest_nums = nums[n+1:]
        for m in range(len(rest_nums)):
            if nums[n] + rest_nums[m] == target:
                return [n, n + m + 1]

def main():
    print(twoSum([-1,-2,-3,-4,-5], -8))

if __name__ == '__main__':
    main()
