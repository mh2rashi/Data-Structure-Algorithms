import math
def searchRange(nums,target):
    # to check if there are any elements within nums
    if len(nums) == 0:
        return [-1, -1]
    # if element is outside the range of nums
    elif target > nums[len(nums) - 1] or target < nums[0]:
        return [-1, -1]
    else:
        i = 0
        # find the first instance of the target and iterate over the list
        while i < len(nums):
            if nums[i] == target:
                start = i
                break
            elif nums[i] > target:
                return [-1, -1]
            else:
                i += 1
        j = start
        # find the last instance of the target iterating over the remaining list starting from the first instance
        while j < len(nums) and nums[j] == target:
            j += 1
        return [start, j - 1]

def searchRange(nums,target):

    # to find the leftmost element
    def findStartingIndex(nums,target):
        index = -1
        start = 0
        end = len(nums) - 1

        while start <= end:
            midpoint = int((start + end)/2)
            # You want to keep on reducing the endpoint until you are at the right end
            if nums[midpoint] >= target:
                end = midpoint - 1
            else:
                start = midpoint + 1

            if nums[midpoint] == target:
                index = midpoint
        return index
    # to find the rightmost element
    def findEndingIndex(nums,target):
        index = -1
        start = 0
        end = len(nums) - 1

        while start <= end:
            midpoint = start + (end-start)/2
            # You want to keep on increasing the start point until you are at the left end
            if nums[midpoint] <= target:
                start = midpoint + 1
            else:
                end = midpoint - 1
            if nums[midpoint] == target:
                index = midpoint
        return index

    result = [findStartingIndex(nums,target),findEndingIndex(nums,target)]
    return result




assert searchRange([5,7,7,8,8,10],8) == [2,4]