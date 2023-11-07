def isPalindrome(x):
    if x < 0:
        return False
    num = 0
    input_num = x
    while input_num // 10 != 0:
        num = num * 10 + input_num % 10
        input_num = input_num // 10
    num = num * 10 + input_num
    if num == x:
        return True
    else:
        return False