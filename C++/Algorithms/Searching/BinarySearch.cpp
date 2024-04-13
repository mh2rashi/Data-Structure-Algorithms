/*

Binary Search: Assuming that the input array is sorted,
compare the element that is being searched for with the element at
the middle of the array. If the element being searched for is greater
than the element at the middle of the array, recursivley check for it
in the second half of the given array. Otherwise, search for it in the
first half od the given array.

Complexity: 

Time: O(log n) as array is halved at each iteration.
Space: O(1)

- Why do we keep going even when `start` is equal to `end`? Becuase we also
want to check for the case when we have one index left.
- `mid` is half of the difference between the starting index and ending index.
Note that if the difference is odd, `mid` would be the floor of the answer,
3 if the difference is 7 (not 3.5)

*/

#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

#include <vector>

int binarySearch(int value, vector<int>& nums) {

    if (nums.size() <= 0) {

        return -1;
    }
    
    int start = 0;
    int end = nums.size() - 1;
    int mid;

    while (start <= end) {

        mid = (start + end)/2;

        if (value < nums[mid]) {

            end = mid - 1;
        }

        else if (value > nums[mid]) {

            start = mid + 1;
        }

        else {

            return mid;
        }

    }

    return -1;
}