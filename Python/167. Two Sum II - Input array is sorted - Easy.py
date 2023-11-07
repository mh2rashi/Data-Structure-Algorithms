#the syntax is: mydict[key] = "value"

def twoSum(numbers,target):
    mydict = {}
    i = 1
    for element in numbers:
        mydict[i] = element
        i += 1
    for i in mydict:
        for j in numbers[i:]:
            if mydict[i] + j == target:
                return [i, numbers.index(j)+1]
            else:
                pass

assert twoSum([0,0,3,4],0) == [1,2]