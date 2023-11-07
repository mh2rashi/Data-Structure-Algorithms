def romanToInt(s):
    dict_1 = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    dict_2 = {'IV': 4, 'IX': 9, 'XL': 50, 'XC': 90, 'CD': 400, 'CM': 900}
    num = 0
    i = 0
    while i < len(s):
        if i == len(s) - 1:
            num += dict_1[s[i]]
        else:
            if s[i:i + 2] in dict_2:
                num += dict_2[s[i:i + 2]]
                i += 2
            else:
                num += dict_1[s[i]]
                i += 1
        return num


assert romanToInt('III') == 3
assert romanToInt('MCMXCIV') == 1994

#Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.