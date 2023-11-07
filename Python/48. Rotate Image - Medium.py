def rotate(matrix):
    """
    Do not return anything, modify matrix in-place instead.
    """
    # first transpose the matrix
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            if i == j:
                pass
            elif i < j:
                switch = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = switch
            else:
                pass
    # flip the matrix horizontally
    for l in range(len(matrix)):
        i = 0
        j = len(matrix) - 1
        if len(matrix)%2 == 0:
            while i > j:
                switch = matrix[l][i]
                matrix[l][i] = matrix[l][j]
                matrix[l][j] = switch
                i += 1
                j -= 1
        else:
            while i != j:
                switch = matrix[l][i]
                matrix[l][i] = matrix[l][j]
                matrix[l][j] = switch
                i += 1
                j -= 1

    return matrix

print(rotate([[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]))