/*

35. Search Insert Position

Given a sorted array of distinct integers and a target value, return the index if the
target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Constraints by Question:
- 1 <= nums.length <= 104
- -104 <= nums[i] <= 104
- nums contains distinct values sorted in ascending order.
- -104 <= target <= 104


*/

/*

Constraints
1. What is the min/max length of the input array?
2. What is the min/max size of the integer within the array?
3. Are the values within the array distinct?
4. based on test case 4, do we provide 0 indexing?





Tets Cases
1. [2], 1 -> 0.
2. [2], 3 -> 1.



Ideas



Complexity:


*/



#include <vector>
#include <algorithm>

using namespace std;


// THis is the closest I got to solving this but my approach is wrong.
int searchInsert(vector<int>& nums, int target) {

        
        if (nums.size() < 1) {
        return 0;
    }


    int start = 0;
    int end = nums.size() -1 ;
    int mid;

    // Check to see if the target is found
    while (start <= end) {

        mid = (start + end)/2;

        if (nums[mid] == target) {
            
            return mid;
        }

        else if (target > nums[mid]) {
            start = mid + 1;
        }

        else {
            end = mid - 1;
        }

    }
        
    mid = (start + end)/2;

    if (target == nums[mid]) {

        return mid;
    }
    else if (target < nums[0]) {
        return 0;

    } else if (target > nums[nums.size() - 1]) {
        return nums.size();

    } else if (nums[mid] < target){
        
        return mid + 1;
    }

    else {

        return mid - 1;
    }
        
    }

};

// Here's the solution that works, it works great with the following two test cases:
// target = 1, [2] in this case the right pointer will be less than left pointer, taking a an index of -1, so we will need to return 0.
// target = 3. [2] in this case the left pointer will be greater than righrt pointer, taking an index of 1 and that is where exactly we want to put 3.
int searchInsert(vector<int>& nums, int target) {
        
    if (nums.size() < 1) {
        return 0;
    }

    int start = 0;
    int end = nums.size() -1 ;
    int mid;

    // Check to see if the target is found
    while (start <= end) {

        mid = (start + end)/2;

        if (nums[mid] == target) {
            
            return mid;
        }

        else if (target > nums[mid]) {
            start = mid + 1;
        }

        else {
            end = mid - 1;
        }

    }
        
    return start;}

};
