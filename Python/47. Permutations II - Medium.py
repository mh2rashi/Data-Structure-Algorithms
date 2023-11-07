def permuteUnique(nums):
    def permutationCreator(number, list_to_permute):
        # if list_to_permute is empty, then just append number to permutation_list (this is for the case  for when
        # nums = [1], so we will send permutationCreator([1],[]))
        if len(list_to_permute) == 0:
            dict[number] = 'value'
        # if we only have 1 element within list_to_permute, then we pretty much have all the combinations in number
        # so we will just be appending number + list_to_permute, notice the writing of code to avoid changing values
        # for variables
        if len(list_to_permute) == 1:
            potential = number + [list_to_permute[0]]
            if potential in dict.values:
                pass
            else:
                dict[potential] = 'value'
                return
                # otherwise we will be iterating over all the elements within the list (adding them to number one by one) and permute over
        # the remainingg list, after taking the number out of it
        else:
            for i in range(len(list_to_permute)):
                permutationCreator(number + [list_to_permute[i]], list_to_permute[:i] + list_to_permute[i + 1:])
        # we sort our input

    nums.sort()
    # create a final list that we will be returning
    # send unique input to our helper function
    dict = {}
    for i in range(len(nums)):
        if nums[i] not in dict:
            dict[nums[i]] = 'number'
            permutationCreator([nums[i]], nums[:i] + nums[i + 1:])
        else:
            pass
    return list(dict.keys())[list(dict.values()).index('value')]


print(permuteUnique([1,1,2]))