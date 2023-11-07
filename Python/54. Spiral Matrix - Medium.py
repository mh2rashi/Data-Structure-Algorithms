def spiralOrder(matrix):
    spiralNumbers = []
    if len(matrix) == 0:
        return spiralNumbers
    top = 0
    right = len(matrix[0]) - 1
    bottom = len(matrix) - 1
    left = 0
    size = len(matrix)*len(matrix[0])
    num_size = 0

    while num_size < size:
        # left to right
        for i in range(len(right)) and num_size < size:
            spiralNumbers.append(matrix[left][i])
            num_size += 1
        left += 1
        # top to bottom
        for i in range(len(bottom)) and num_size < size:
            spiralNumbers.append(matrix[i][bottom])
            num_size +=1
        top += 1
        # left to right












print(spiralOrder(
    [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12]
    ]))