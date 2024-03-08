/*

217. Contains Duplicate
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

*/

/*

Constraints

1. What is the maximum and minimum size of the array?
2. Does the array only contain integers? Is there a range for the integers? min/max values?
3. The array has to be unique
4. Do you prefer the output to be 0 or 1? or would you like me to return true or false?
5. Would the input always be valid (an array of integers?) What should I do if it's not valid? DO nothing or raise an exception?

Tets Cases

1. [] -> false
2. [1] -> false
3. [-1, 2] -> false
4. [4, 4, 8 , 8] -> true
5. [1,2,3,4,1] -> true

Ideas & Complexity

1. Brute force would be to have nested for loop and check if the element appears twice within the list. This would have O(n^2) time complexity. O(n) space complexity.
This actually ran into time complexity issues as I didn't factor in the array being very very big.
2. Another way would be to sort the array and then just check if the adjacent elements match? O(nlogn) time and O(n) space complexity.
3. The third option would be to have a set to which you keep on adding elements and it returns false if you add an element that already exists. O(n) space and time complexity.


*/

#include <vector>
#include <cassert>
#include <unordered_set>
#include <algorithm>

using namespace std;

class ContainsDuplicate {

    public:

    // May not work very very big arrays.
    bool solution1(vector<int>& nums) {

        if (nums.size() < 2) {
            return false;
        }

        for (int i = 0; i < nums.size(); i++) {

            for (int j = 1; j < nums.size(); j++) {

                if ( i != j && nums[i] == nums[j]) {
                    return true;
                }
            }
        }

        return false;

    }

    bool solution2(vector<int>& nums) {

        if (nums.size() < 2) {
            return false;
        }

        // sort the array
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        return false;
    }

    bool solution3(vector<int>& nums) {

        if (nums.size() < 2) {
            return false;
        }

        unordered_set<int> unique_nums;

        for (int i = 0; i < nums.size(); i++) {
            if (!unique_nums.insert(nums[i]).second) {
                return true;
            }
        }

        return false;
    }

};

int main() {

    ContainsDuplicate containsDuplicate;

    // Test 1
    vector<int> array1 = {};
    assert(containsDuplicate.solution1(array1) == false);
    assert(containsDuplicate.solution2(array1) == false);
    assert(containsDuplicate.solution3(array1) == false);

    // Test 2
    vector<int> array2 = {1};
    assert(containsDuplicate.solution1(array2) == false);
    assert(containsDuplicate.solution2(array2) == false);
    assert(containsDuplicate.solution3(array2) == false);

    // Test 3
    vector<int> array3 = {-1, 2};
    assert(containsDuplicate.solution1(array3) == false);
    assert(containsDuplicate.solution2(array3) == false);
    assert(containsDuplicate.solution3(array3) == false);

    // Test 4
    vector<int> array4 = {4, 4, 8 , 8};
    assert(containsDuplicate.solution1(array4) == true);
    assert(containsDuplicate.solution2(array4) == true);
    assert(containsDuplicate.solution3(array4) == true);

    // Test 5
    vector<int> array5 = {1,2,3,4,1};
    assert(containsDuplicate.solution1(array5) == true);
    assert(containsDuplicate.solution2(array5) == true);
    assert(containsDuplicate.solution3(array5) == true);

    return 0;
};
