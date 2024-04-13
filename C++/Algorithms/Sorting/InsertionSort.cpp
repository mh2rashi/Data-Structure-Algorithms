/* Insertion Sort Algorithm

Builds the final sorted array (or list) one item at a time. Iterates over each element
in the array and, in each iteration, it finds the correct position to insert the current element into
the sorted array.

Here's the algorithm.
1. Start with the second element (index 1) and consider it as the key.
2. Compare the key with the elements before it, moving them forward until finding the correct position for the key.
3. Insert the key into its correct position.
4. Repeat the process for the next element.


Complexity:
Time: O(N^2), Space: O(1)

*/


#include <vector>
#include <cassert>

using namespace std;

#include <vector>

void insertionSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        int key = nums[i];
        int j = i - 1;

        // Move elements of nums[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = key;
    }
}


