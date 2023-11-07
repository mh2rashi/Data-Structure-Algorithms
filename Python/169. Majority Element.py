def majorityElement(nums):
    list_unique = []
    list_count = []
    for element in nums:
        if element in list_unique:
            pass
        else:
            list_unique.append(element)
    for element in list_unique:
        list_count.append(nums.count(element))
    return list_unique[list_count.index(max(list_count))]



assert majorityElement([3,2,3]) == 3