/*

33. Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k],
nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

Constraints by Question:
- 1 <= nums.length <= 5000
- 104 <= nums[i] <= 104
- All values of nums are unique.
- nums is an ascending array that is possibly rotated.
- 104 <= target <= 104

*/

/*

Constraints
1. What is the min/max length of the input array?
2. What is the min/max size of the integer within the array?



Tets Cases
1. [4,5,6,7,8,1,2,3], 8 -> 4
2. [8,3,4,5,6,7], 3 -> 1
3. [1], 0 -> -1
4. [1,2], 2 -> 1



Ideas
1. Brute force would be to just iterate throught the array and find the integer
and if tis found, then we just return the integer.
2. A modified Binary Search would work by finding the sorted array, see if 
our target is within its bounds and then running binary search on the sorted array.
If not then we would explore the rotated array. We use Binary Search recursively and if we don't
find the target, then we just return -1.


Complexity:
1. Time: O(N), Space: O(1); where N is the number of itnegers within the array.
2. Time: O(log N), Space: O(1); where N is the number of integers within the array.

*/



#include <vector>
#include <algorithm>

using namespace std;


int search(vector<int>& nums, int target) {

    if (nums.size() <= 0) {
        return -1;
    }


    int start = 0;
    int end = nums.size() -1 ;
    int mid;


    while (start <= end) {

        mid = (start + end)/2;


        if (nums[mid] == target) {
            
            return mid;
        }

        // Identify the sorted portion of the array
        else if (nums[start] <= nums[mid]) {

            // Check if the target is within its bound
            if (target >= nums[start] && target <= nums[mid]) {

                end = mid - 1;
            }
            // If not, then we can check the other portion of the array.
            else {

                start = mid + 1;

            }

        } 

        // Identify the sorted portion of the array
        else {

            // Check if the target is within its bound
            if (target >= nums[mid] && target <= nums[end]) {

                start = mid + 1;
            }

            // If not, then we can check the other portion of the array.
            else {

                end = mid - 1;

            }
        }

    }


    return -1;

};
