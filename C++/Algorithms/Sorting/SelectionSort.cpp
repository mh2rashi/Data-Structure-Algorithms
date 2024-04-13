/* Selection Sort Algorithm

Divide the list (unsorted and sorted parts).
Initially sorted sublist is empty and unsorted sublist the entire list.
Find the smallest element in the unsorted list and swap it with the leftmost
unsorted element, and moving the sublist boundaries.

Complexity:
Time: O(N^2), Space: O(1)

*/


#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


vector<int> selectionSort(vector<int>& nums) {
    for (int leftPtr = 0; leftPtr < nums.size(); leftPtr++) {
        for (int rightPtr = leftPtr + 1; rightPtr < nums.size(); rightPtr++) {
            if (nums[leftPtr] > nums[rightPtr]) {
                swap(nums[leftPtr], nums[rightPtr]);
            }
        }
    }
    return nums;
}

