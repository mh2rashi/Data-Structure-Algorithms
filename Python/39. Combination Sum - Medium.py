def combinationSum(candidates, target):
    # helper function
    def generate(curr, curr_names):
        # if the sum of curr is greater than target than we will return
        if sum(curr) > target:
            return
        # if the sum of curr is equal to target, then we will append to results
        elif sum(curr) == target:
            results.append(curr)
            return
        # otherwise we will run a for loop in which we will append an element to curr and send an updates curr_names
        for i in range(len(curr_names)):
            generate(curr + [curr_names[i]], curr_names[i:])

    results = []
    generate([], candidates)

    # return results
    return results

print(combinationSum([2,3,6,7],7))

