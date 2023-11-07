def lengthOfLongestSubstring(s):
    string = ''
    max_list = 0
    if len(s) == 1:
        return 1
    if len(s) == 0:
        return 0
    for element in s:
        if element in string:
            max_list = max(max_list, len(string))
            string = string[string.index(element)+1:]
            string += element
        else:
            string += element
        max_list = max(max_list, len(string))
    return max_list

assert lengthOfLongestSubstring("abcabcbb") == 3
assert lengthOfLongestSubstring("bbbbb") == 1
assert lengthOfLongestSubstring("pwwkew") == 3
assert lengthOfLongestSubstring("dvdf") == 3