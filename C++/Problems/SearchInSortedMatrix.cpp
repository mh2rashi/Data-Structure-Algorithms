/*

74. Search a 2D matrix

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Constraints by Question:
- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 100
- -104 <= matrix[i][j], target <= 104

 
*/

/*

Constraints

1. What is the min/max size of the 2D matrix?
2. What is the min/max size of integers within the array?

Tets Cases
1. matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3 -> True
2. matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13

Ideas
1. We run a binary search on the first column and check if the target
is within the range (row_start, row_end). If yes, then we explore that specific row
by running a binary search on it.
2. Brute force would be to traverse through each of the integers within the matrix and return true
if we found the integer and false otherwise.
3. This is an efficient solution, whihc works on the following optimization: start from the lowest-left
if target > current position: move to the right
if target < current position: move upwards


Complexity:
1. Time: O(log m*n), Space: O(1).
2. Time: O(m*n)
3. Since we traverse the matrix only once and at each step,
and we eliminate an entire row or column, the time complexity is now O(n+m).


*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

class SearchA2DMatrix {
public:

    bool solution1(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size() - 1;
        int cols = matrix[0].size() - 1;

        int start = 0;
        int end = rows;
        int mid;

        int chosen_row = -1;

        // Code to find the appropriate row for binary search
        while (start <= end) {
            
            mid = (start + end)/2;

            if (target < matrix[mid][0]) {

                end = mid - 1;

            }

            else if (target > matrix[mid][cols]) {

                start = mid + 1;
            }

            else {

                chosen_row = mid;
                break;
            }

        }
        
        if (chosen_row == -1) {
            return false;
        }
        
         start = 0;
         end = cols;

        while (start <= end) {
            
            mid = (start + end)/2;

            if (target == matrix[chosen_row][mid]) {

                return true;

            }

            else if (target > matrix[chosen_row][mid]) {

                start = mid + 1;
            }

            else {

                end = mid - 1;
            }

        }

        return false;
    
    
    }

    bool solution2(vector<vector<int>>& matrix, int target) {

        for (int i = 0; i < matrix.size(); i++) {

            for (int j = 0; j < matrix[0].size(); j++) {

                if (matrix[i][j] == target) {
                    return true;
                }

            }

        }

        return false;

    }

    // THis solution is wrong
    bool solution3(vector<vector<int>>& matrix, int target) {

        int curr_row = 0;
        int curr_col = 0;

        int max_row = matrix.size() - 1;
        int max_col = matrix[0].size() - 1;

        while (curr_row >= 0 && curr_row <= max_row && curr_col >= 0 && curr_col <= max_col) {

            if (target == matrix[curr_row][curr_col]) {
                return true;
            }

            else if (target < matrix[curr_row][curr_col]) {
        
                if (curr_col == max_col) {
                    curr_col = 0;
                    curr_row += 1;
                }

                else {

                    curr_row += 1;
                }
            }

            else {

                curr_col -= 1;

            }

        };

    return false;

    }

    // Here's the correct solution, figure out why this is correct
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int row = 0;
        int col = cols - 1; // Start from the top-right corner

        while (row < rows && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--; // Move left
            } else {
                row++; // Move down
            }
        }

        return false; // Element not found
    }

};

int main() {

    return 0;
}