import collections
'''
def isValidSudoku(board):
    for i in range(0, 9):
        # check for duplicates in each row
        row_i = board[i]
        list_of_duplicates = [item for item, count in collections.Counter(row_i).items() if count > 1]
        if len(list_of_duplicates) > 1:
            return False
        # check for duplicates in each column
        column_i = [board[j][i] for j in range(9)]
        list_of_duplicates = [item for item, count in collections.Counter(column_i).items() if count > 1]
        if len(list_of_duplicates) > 1:
            return False
        for j in range(9):

    return True
'''


def isValidSudoku(self, board: List[List[str]]) -> bool:
    # We make a list of sets for rows, columns and boxes
    rows = [set() for _ in range(9)]
    cols = [set() for _ in range(9)]
    boxes = [set() for _ in range(9)]
    for i in range(9):
        for j in range(9):
            if board[i][j] == '.':
                continue
            num = int(board[i][j])
            # Creating Box ID, e.g. 0, 1, 2, 3 moving horizontally down the big box
            boxIdx = (i // 3) * 3 + j // 3
            # checking if element is already present within the set, if , yes return false
            if num in rows[i] or num in cols[j] or num in boxes[boxIdx]:
                return False
            # Otherwise we add in the element
            rows[i].add(num)
            cols[j].add(num)
            boxes[boxIdx].add(num)
    return True


assert isValidSudoku([
  [[".",".",".",".","5",".",".","1","."],
   [".","4",".","3",".",".",".",".","."],
   [".",".",".",".",".","3",".",".","1"],
   ["8",".",".",".",".",".",".","2","."],
   [".",".","2",".","7",".",".",".","."],
   [".","1","5",".",".",".",".",".","."],
   [".",".",".",".",".","2",".",".","."],
   [".","2",".","9",".",".",".",".","."],
   [".",".","4",".",".",".",".",".","."]]
]) == False

