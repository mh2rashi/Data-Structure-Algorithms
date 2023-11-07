def isPalindrome(x:int) -> bool:
    integer = 0
    if x < 0:
        return False
    while x//10 != 0:
        integer = (x % 10)*10 + integer*10
        x = x//10
    integer = integer + x % 10
    return integer == x







isPalindrome(121)