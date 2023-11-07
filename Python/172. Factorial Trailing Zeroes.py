import math

def trailingZeroes(n):
    trailing_zeroes = 0
    while n >= 5:
        n = math.floor(n/5)
        trailing_zeroes += n
    return trailing_zeroes

assert trailingZeroes(5) == 1



