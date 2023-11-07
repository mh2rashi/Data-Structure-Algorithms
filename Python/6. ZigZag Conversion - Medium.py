def convert(s,numRows):
    row = 0
    delta = -1
    res = [[] for i in range(numRows)]
    if numRows > len(s) or numRows == 1:
        return s
    for character in s:
        res[row].append(character)
        if row == 0 or row == numRows - 1:
            delta *= -1
            row += delta
        else:
            row += delta
    for i in range(len(res)):
        res[i] = ''.join(res[i])
    return ''.join(res)

assert convert("PAYPALISHIRING",3) == "PAHNAPLSIIGYIR"