'''def canJump(nums):
    steps = []
    for i in range(len(nums) - 1):
        steps.sort()
        if nums[i] != 0:
            steps.append(nums[i])
        elif nums[i] == 0 and sum(steps) >= len(steps) * (len(steps) + 1) / 2:
            steps.append(nums[i])
        else:
            return False
    return True'''

def canJump(nums):
    lastGoodPosition = len(nums) - 1
    for i in range(len(nums)-2,-1,-1):
        if nums[i] + i >= lastGoodPosition:
            lastGoodPosition = i
        else:
            pass
    if lastGoodPosition == 0:
        return True
    else:
        return False



print(canJump([2,3,1,1,4]))
print(canJump([3,0,0,0]))

# Video form Nick White https://www.youtube.com/watch?v=Zb4eRjuPHbM