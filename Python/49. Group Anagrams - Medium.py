def groupAnagrams(strs):
    dict = {}
    result = []
    for i in range(len(strs)):
        sorted_character = sorted(strs[i])
        sorted_character = "".join(sorted_character)
        if sorted_character in dict:
            update = dict[sorted_character] + [strs[i]]
            dict[sorted_character] = update
        else:
            dict[sorted_character] = [strs[i]]

    return dict.values()

print(groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))