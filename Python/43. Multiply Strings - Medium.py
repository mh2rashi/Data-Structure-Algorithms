def multiply(num1,num2):
    # The final number we will be returning
    final = 0
    # this is the 'x' that we put in multiplication after we multiply in the new line
    increment = 0
    for i in num1[::-1]:
        # carry a number > 9
        carry = 0
        # this is to get the right addition after multiplying strings
        space = 0
        # for building our current integer
        num = 0
        for j in num2[::-1]:
            # this is the statement for when there is a carry over and we are not on the last digit
            if ( int(i)*int(j) + carry ) > 9 and j != num2[0]:
                num += ((int(i)*int(j) + carry)%10)*10**space
                carry = (int(i)*int(j) + carry)//10
                space += 1

            else:
                num += ((int(i)*int(j)+carry))*10**space
                carry = 0
                space += 1
        # after each successive for loop we add the number to final and increment the larger X
        #  by 1
        final += num*10**increment
        increment += 1
    return str(final)


print(multiply("36","23"))