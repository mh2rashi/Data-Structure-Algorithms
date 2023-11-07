def divide(dividend, divisor):
    # Helper function to get the quotient
    def helper(dividend, divisor):
        i = 1
        quotient = 0
        # We run the loop while dividend is greater than the divisor
        while dividend >= divisor:
            # We essentially do, for example (dividend = 10, divisor = 3) 10 - 3(2^1), 10 - 3(2^2) -> we subtract until we are
            # negative. So we'll stop at 10 - 3(2^1), and then we'll update our number in the else statement, and start
            # again with i = 1. So our next iteration will be 4 - 3(2^1) and we'll add 2**(1-1) to our i and we'll get
            # quotient = 3
            if dividend - divisor * (2 ** i) >= 0:
                i += 1
            else:
                quotient += 2 ** (i - 1)
                dividend = dividend - divisor * 2 ** (i - 1)
                i = 0
        return quotient

    int_max = 2 ** 31 - 1
    int_min = -2 ** 31

    # We have to send the helper function only positive integers and then attach the sign in the end.
    if dividend < 0 and divisor < 0:
        return min(helper(dividend*-1,divisor*-1),int_max)
    elif dividend < 0:
        return max(-1*helper(dividend*-1,divisor),int_min)
    elif divisor < 0:
        return max(-1*helper(dividend,divisor*-1),int_min)
    else:
        return min(helper(dividend, divisor), int_max)




print(divide(1000, 2))


