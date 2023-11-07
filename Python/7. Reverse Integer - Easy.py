import math

def reverse(x):
    input_num = x
    if x // 10 == 0:
        return x
    elif input_num < 0:
        input_num = input_num * -1
        num = 0
        while input_num // 10 != 0:
            num = num * 10 + input_num % 10
            input_num = input_num // 10
        num = num * 10 + input_num
        if num * -1 < int(math.pow(-2, 31)):
            return 0
        else:
            return num * -1
    else:
        num = 0
        while input_num // 10 != 0:
            num = num * 10 + input_num % 10
            input_num = input_num // 10
        num = num * 10 + input_num
        if num > int(math.pow(2, 31) - 1):
            return 0
        else:
            return num

assert reverse(1534236469) == 0
assert reverse(123) == 321