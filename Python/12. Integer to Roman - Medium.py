def intToRoman(num):
    values = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
    string = ['M','CM','D','CD','C','XC','L','XL','X','IX','V','IV','I']
    i = 0
    r_string = ''
    while num > 0:
        if num - values[i] >= 0:
            r_string += string[i]
            num -= values[i]
        else:
            i += 1
    return r_string


def intToRoman(num):
    roman_number = ''
    while num > 0:
        if num > 999:
            roman_number += 'M' * (num // 1000)
            num = num % 1000
        elif num > 99:
            if num >= 900:
                num = num % 900
                roman_number += 'CM'
            elif num >= 500:
                num = num % 500
                roman_number += 'D'
            elif num >= 400:
                num = num % 400
                roman_number += 'CD'
            else:
                roman_number += 'C' * (num // 100)
                num = num % 100
        elif num > 9:
            if num >= 90:
                num = num % 90
                roman_number += 'XC'
            elif num >= 50:
                num = num % 50
                roman_number += 'L'
            elif num >= 40:
                num = num % 40
                roman_number += 'XL'
            else:
                roman_number += 'X' * (num // 10)
                num = num % 10
        else:
            if num == 9:
                num = num % 9
                roman_number += 'IX'
            elif num >= 5:
                num = num % 5
                roman_number += 'V'
            elif num == 4:
                num = num % 4
                roman_number += 'IV'
            else:
                roman_number += 'I' * num
                num = num % num
    return roman_number

assert intToRoman(3) == "III"
assert intToRoman(4) == "IV"
assert intToRoman(9) == "IX"
assert intToRoman(58) == "LVIII"
assert intToRoman(1994) == "MCMXCIV"
