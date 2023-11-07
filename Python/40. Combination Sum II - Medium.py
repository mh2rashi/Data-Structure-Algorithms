def combinationSum2(candidates, target):
    def generate(curr, candidates_list):
        # if the sum of curr is equal to target, then we will append to results
        if sum(curr) == target:
            # we need to check for duplicates
            if curr in results:
                return
            else:
                results.append(curr)
                return
        # if the sum of curr is greater than target than we will return
        elif sum(curr) + candidates[0] > target :
            return
        # otherwise we will run a for loop in which we will append an element to curr and send an updated curr_names
        # notice the subtlety here that we send our recursive function candidates_list[i +1:] because we can only use an
        # integer only once
        for i in range(len(candidates_list)):
            generate(curr + [candidates_list[i]], candidates_list[i + 1:])

    results = []
    candidates.sort()
    generate([], candidates)
    return results

print(combinationSum2([10,1,2,7,6,1,5],8))
