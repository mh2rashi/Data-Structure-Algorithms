/*

1. Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
 
*/

/*

Constraints

1. Exactly one solution, only integers, can't use the same element twice, return the answer in any order.
2. Is there a minimum and maximum length to the array? (2 to 10^4)
3. Is there a min and max integer? (-10^9 to 10^9)
4. Only one valid answer exists.

Tets Cases

1. [0,0] 0 -> [0,1]
2. [1,3,4] 5 -> [0,2]
3. [-1, 2, 1] 1 -> [0,1]
4. [-3,4,7] 4 -> [0,2]

Ideas

1. Have a nested for loop and searh for two integers and return their indices. Time O(N^2), Space O(1).
2. Have a map with the integer as key and index as value, and check to see if the SUM - CURRENT_INT exists within the map, if so then return both integers indexes.
3. Sort the list and then have two pointers from each end and increment if the current sum is smaller and decrement the right pointer if the current sum is larger.

Complexity:
1. Time O(N^2), Space O(1).
2. Time O(N), Space O(N).
3. Time (ONlogN), Space O(1)

*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

class TwoSum {
public:
    vector<int> solution1(vector<int> nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // Return empty vector if no solution found
    }

    vector<int> solution2(vector<int> nums, int target) {
        unordered_map<int, int> traversed_nums;
        for (int i = 0; i < nums.size(); i++) {
            if (traversed_nums.find(target - nums[i]) != traversed_nums.end()) {
                return {traversed_nums[target - nums[i]], i};
            } else {
                traversed_nums[nums[i]] = i;
            }
        }
        return {}; // Return empty vector if no solution found
    }

};

int main() {

    TwoSum twoSum;

    vector<int> nums1 = {0,0};
    int target1 = 0;
    vector<int> result1 = {0,1};

    // Test 1
    assert(twoSum.solution1(nums1,target1) == result1);
    assert(twoSum.solution2(nums1,target1) == result1);

    // Test 2
    vector<int> nums2 =  {1,3,4};
    int target2 = 5;
    vector<int> result2 = {0,2};

    assert(twoSum.solution1(nums2,target2) == result2);
    assert(twoSum.solution2(nums2,target2) == result2);

    // Test 3
    vector<int> nums3 = {-1, 2, 1};
    int target3 = 1;
    vector<int> result3 = {0,1};

    assert(twoSum.solution1(nums3, target3) == result3);
    assert(twoSum.solution2(nums3, target3) == result3);

    // Test 4
    vector<int> nums4 {-3,4,7};
    int target4 = 4;
    vector<int> result4 = {0,2};

    assert(twoSum.solution1(nums4, target4) == result4);
    assert(twoSum.solution2(nums4, target4) == result4);

    return 0;
}
