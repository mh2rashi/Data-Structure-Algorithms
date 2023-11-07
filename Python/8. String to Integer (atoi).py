def myAtoi(str):
    max_int = 2 ** 31 -1
    min_int = -2 ** 31

    i = 0
    res = 0
    negative = 1

    #whitespace
    while i < len(str) and str[i] == ' ':
        i += 1

    #+/- symbol
    if i < len(str) and str[i] == '-':
        i += 1
        negative = -1
    elif i < len(str) and str[i] == '+':
        i += 1

    checker = set('0123456789')
    while i < len(str) and str[i] in checker:
        res = res*10 + int(str[i])
        i += 1

    #check th Max/Min
    res = res*negative
    if res < 0:
        return max(res,min_int)
    return min(res,max_int)



assert myAtoi("42") == 42
assert myAtoi("   -42") == -42