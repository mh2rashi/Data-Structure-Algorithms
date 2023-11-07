def permute(nums):
    permutations_list = []

    def permutationCreator(number, list_to_permute):
        # if the length of the list sent to permute is equal to 1, then just append the last element and append to
        # permutations_list
        if len(list_to_permute) == 1:
            number.append(list_to_permute[0])
            permutations_list.append(number)

        else:
            for i in range(len(list_to_permute)):
                # append the next element in list_to_permute to number
                number.append(list_to_permute[i])
                add_back = list_to_permute[i]
                # take that number out of list_to_permute
                list_to_permute.pop(i)
                # send the recursive function
                permutationCreator(number, list_to_permute)
                # add back the element into list_to_permute
                list_to_permute.append(add_back)
                # sort
                list_to_permute.sort()
                # bring back number to where it was beginning of the loop
                number = number[:-len(list_to_permute)]

    # first sort nums
    nums.sort()
    # if nums is 1 number then just return the number
    if len(nums) == 1:
        return [nums]
    # else we create a permutation for each of the numbers within the list
    for i in range(len(nums)):
        # pick the first number
        number = nums[i]
        # pop it out of nums
        nums.pop(i)
        # send the recursive function the number with the remaining nums excluding the number
        permutationCreator([number], nums)
        # add back number into nums
        nums.append(number)
        # sort nums
        nums.sort()
    return permutations_list


print(permute([1, 2, 3]))
