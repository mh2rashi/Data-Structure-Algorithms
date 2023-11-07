def generateParenthesis(n):
    # helper function
    def helper(l, r, combination, list_combos):
        # append the string if l and r are 0.
        if l == 0 and r == 0:
            list_combos.append(combination)
        # return none if you have more left brackets than right brackets
        elif l > r:
            return None
        # return none if you have negative number of left brackets
        elif l < 0:
            return None
        else:
            # you run the recursion with both sides
            string_left = combination + '('
            string_right = combination + ')'
            helper(l - 1, r, string_left, list_combos)
            helper(l, r - 1, string_right, list_combos)
        return list_combos
    # you return the helper
    return helper(n, n, '', [])


print(generateParenthesis(3))
