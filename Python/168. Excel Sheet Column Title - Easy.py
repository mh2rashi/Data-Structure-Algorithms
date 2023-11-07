def convertToTitle(n):
    mydict = {'A': 1, 'C': 3, 'B': 2, 'E': 5, 'D': 4, 'G': 7, 'F': 6, 'I': 9, 'H': 8, 'K': 11, 'J': 10, 'M': 13,
              'L': 12, 'O': 15, 'N': 14, 'Q': 17, 'P': 16, 'S': 19, 'R': 18, 'U': 21, 'T': 20, 'W': 23, 'V': 22,
              'Y': 25, 'X': 24, 'Z': 26}
    if n in mydict.values():
        return (list(mydict.keys())[list(mydict.values()).index(n)])
    else:
        list_q = []
        while n > 26:
            quotient = n // 26
            if quotient > 1:
                list_q.append(1)
                n = quotient
            else:
                list_q.append(quotient)
                list_q.append(n % 26)
                words = ""
                for element in list_q:
                    words += (list(mydict.keys())[list(mydict.values()).index(element)])
                return words


assert convertToTitle(703) == "AAA"
assert convertToTitle(52) == "AA"
