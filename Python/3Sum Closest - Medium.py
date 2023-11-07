def threeSumClosest(nums, target):
    new_max = abs((nums[0]+nums[1]+nums[2]) - target)
    for i in range(0, len(nums)-1):
        for j in range (i + 1,len(nums)-2):
            for k in range(j + 1,len(nums)-3):
                closest = abs((nums[i]+nums[j]+nums[k]) - target)
                new_max = max(closest,new_max)
    return new_max

assert threeSumClosest([-1,2,1,-4],1) == 2