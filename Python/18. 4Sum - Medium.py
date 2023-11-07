def fourSum(nums,target):
    if len(nums) < 4:
        return []
    if len(nums) == 4 and nums[0] + nums[1] + nums[2] + nums[3] == target:
        return [nums]
    list_of_qds = []
    nums.sort()
    for i in range(0, len(nums) - 3):
        q = i + 1
        for j in range(q, len(nums) - 2):
            k = j + 1
            l = len(nums) - 1
            while k < l:
                if nums[i] + nums[j] + nums[k] + nums[l] == target:
                    list_of_qds.append([nums[i], nums[j], nums[k], nums[l]])
                    while k < len(nums) - 1 and nums[k] == nums[k+1]:
                        k += 1
                    while l > k and nums[l] == nums[l-1]:
                        l -= 1
                elif nums[i] + nums[j] + nums[k] + nums[l] > target:
                    l -= 1
                else:
                    k += 1
            while j + 1 < len(nums) - 1 and nums[j + 1] == nums[j]:
                j += 1
        while i + 1 < len(nums) - 1 and nums[i + 1] == nums[i]:
            i += 1
    return list_of_qds

assert fourSum([-1,-1,0,0,1],-1) == [[-1,-1,0,1],[-1,-1,0,1]]