def nextPermutation(nums):
        """
        Do not return anything, modify nums in-place instead.
        """
        # Helper function to swap two indices
        def swap(nums, ind1, ind2):
            curr = nums[ind1]
            nums[ind1] = nums[ind2]
            nums[ind2] = curr
        # This reverses a descending list into an ascending list
        def reverse(nums, beg, end):
            while beg < end:
                swap(nums, beg, end)
                beg += 1
                end -= 1
        # WSe swap since we don't have to return anything
        if len(nums) == 1:
            return
        # We swap because either it's gonna be the biggest or smallest number possible
        if len(nums) == 2:
            return swap(nums, 0, 1)
        # Variable to represent our first non-ascending index
        dec = len(nums) - 2
        # While loop to get till the first non-ascending number from the left
        while dec >= 0 and nums[dec] >= nums[dec + 1]:
            dec -= 1
        # To return an ascending list from the right
        reverse(nums, dec + 1, len(nums) - 1)
        # This means that our list was in an ascending order form the left, so we just return the ascending list from
        # the right
        if dec == -1:
            return
        # Otherwise we want to get the number that was the first non-ascending number from the left
        next_num = dec + 1
        # We want to find the two numbers that we want to swap
        while next_num < len(nums) and nums[next_num] <= nums[dec]:
            next_num += 1
        swap(nums, next_num, dec)
        return nums

assert nextPermutation([1,7,9,9,8,3]) == [1,8,3,7,9,9]


