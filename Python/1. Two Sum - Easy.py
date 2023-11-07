def twoSum(nums,target):
    if len(nums) < 1:
        return false
    Dict = {}
    for i in range(len(nums)):
        if target - nums[i] in Dict:
            return [i, Dict[target - nums[i]]]
        else:
            Dict[nums[i]] = i
            i += 1

assert twoSum([2,7,11,15],9)
assert twoSum([3,2,4],6)