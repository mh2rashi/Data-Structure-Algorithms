def generate(numRows):
    list_return = []
    i = 0
    if i == 0:
        return [[1]]
    else:
        while i < numRows:
            if i == 0:
                list_return.append([1])
                i = i + 1
            elif i == 1:
                list_return.append([1,1])
                i = i + 1
            else:
                list_temporary = [1]
                previous_list = list_return[-1]
                j = 0
                while j < len(previous_list) - 1:
                    if j + 1 == len(previous_list) - 1:
                        sum_now = previous_list[j] + previous_list[j + 1]
                        list_temporary.append(sum_now)
                        list_temporary.append(1)
                        j = j +1
                    else:
                        sum_now = previous_list[j] + previous_list[j + 1]
                        list_temporary.append(sum_now)
                        j = j + 1
                list_return.append(list_temporary)
                i = i + 1
        return list_return

assert generate(5) == [
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]