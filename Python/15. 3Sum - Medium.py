def threeSum(nums):
    if len(nums) < 3:
        return []
    nums.sort()
    list_of_triplets = []
    for i in range(0, len(nums) - 2):
        if i >= 0 and nums[i] != nums[i - 1]:
            l = i + 1
            r = len(nums) - 1
            while l < r:
                if nums[i] + nums[l] + nums[r] == 0:
                    list_of_triplets.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    r -= 1
                    l += 1
                elif nums[i] + nums[l] + nums[r] > 0:
                    r -= 1
                else:
                    l += 1
        return list_of_triplets

assert threeSum([-1,0,1,2,-1,-4]) == [[-1, -1, 2], [-1, 0, 1]]