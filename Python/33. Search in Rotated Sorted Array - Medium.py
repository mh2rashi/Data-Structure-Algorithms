
'''def search(nums,target):
    # Statement to check an empty list
    if len(nums) == 0:
        return -1
    # Statement to check if the list is of length 1 and the target is within the list
    elif len(nums) == 1 and nums[0] == target:
        return 0
    # Statement to check if the target is not within the range of the list
    elif target < nums[0] and target > nums[len(nums)-1]:
        return -1
    # Statement to check if the target is present from the left of the list
    elif target <= nums[len(nums) -1]:
        i = len(nums) - 1
        while i >= 0:
            if nums[i] == target:
                return i
            else:
                i -= 1
        return i
    # Target must be from the right of the list
    else:
        i = 0
        while i < len(nums):
            if nums[i] == target:
                return i
            else:
                i += 1
        return -1 '''

def search(nums,target):
   # Statement to check if nums is empty
    if len(nums) == 0:
        return - 1
    left = 0
    right = len(nums) - 1
   # Statement to check the pivoting element
    while left < right:
        midpoint = int((left + right) / 2)
        if nums[midpoint] > right:
            left = midpoint + 1
        else:
            right = midpoint

    start = left    # Beginning of Pivot
    left = 0        # Very first element
    right = len(nums) - 1 # Very last element

    #check if element is within the pivot set
    if target >= nums[start] and target <= nums[right]:
        # if yes then left = start = midpoint and right = len(nums) - 1
        left = start
    else:
        # If no, then right = midpoint and left = 0
        right = start
    # Standard binary search
    while left <= right:
        midpoint = int((left + right) / 2)
        if nums[midpoint] < target:
            left = midpoint + 1
        else:
            right = midpoint - 1
        if nums[midpoint] == target:
            return midpoint
    return -1

assert search([3,4,5,6,1,2],2) == 1
