/* Bubble Sort Algorithm

Also known as 'sinking sort'. Compare adjacent pairs of elements and swapping them if they are in the wrong order.
Repeated until array is sorted. A bubble passes over the array and 'catches' the maximum/minimum element and brings
it over to the right side.

Complexity:
Time: O(N^2), Space: O(1)

*/


#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

#include <vector>

vector<int> bubbleSort(vector<int>& nums) {
    
    bool sorted = false;

    while (!sorted) {
        sorted = true;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                swap(nums[i], nums[i - 1]);
                sorted = false;
            }
        }
    }

    return nums;
}

