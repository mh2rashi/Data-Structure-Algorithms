/*

75. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Constraints by Question:
- n == nums.length
- 1 <= n <= 300
- nums[i] is either 0, 1, or 2.

Follow up: Could you come up with a one-pass algorithm using only constant extra space?
 
*/

/*

Constraints
1. What is the min/max length of the input array?
2. What is the min/max size of the integer within the array?
3. Can there only be three colors within the array?
4. Can you use extra memory?

Tets Cases
1. [1, 0, 2, 1] -> [0, 1, 1, 2] -> biggest edge case.
2. [1] -> [1]
3. [2,0,1] -> [0,1,2]

Ideas
1. Use a hash map to store the frequency and then just re-write all of the integers onto our array.
2. Could implement quick sort (in-place) or merge sort.
3. Watched video for one-pass solution - use 3 pointers; https://www.youtube.com/watch?v=6sMssUHgaBs

Complexity:
1. Time: O(N), O(1): Space
2. 
3.

*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

class SortColors {
public:

    vector<string> solution1(vector<int>& nums) {

        int start = 0;
        int index = 0;
        int end = nums.size() - 1;

        while (index <= end) { // This is something that threw me off, you have to have <= as the condition

            if (nums[index] == 0) {

                nums[index] = nums[start];
                nums[start] = 0;

                start++;
                index++;
            }

            else if (nums[index] == 2) {

                nums[index] = nums[end];
                nums[end] = 2;
                // Why don't we increment start when we swap with 2 because it's already taken care of. Need to explore this further.
                end--;
            }

            else {

                index++;
            }
        
        }
       
    }

    vector<string> solution3(vector<int>& nums) {

        int start = 0;
        int index = 0;
        int end = nums.size() - 1;

        while (index <= end) { // This is something that threw me off, you have to have <= as the condition

            if (nums[index] == 0) {

                nums[index] = nums[start];
                nums[start] = 0;

                start++;
                index++;
            }

            else if (nums[index] == 2) {

                nums[index] = nums[end];
                nums[end] = 2;

                end--;
            }

            else {

                index++;
            }
        
        }
       
    }

};

int main() {

    GroupAnagram groupAnagram;

    // Test 1
    vector<string> input1 = {"eat","seat","tea"};
    vector<vector<string>> output1 = {{"seat"}, {"eat","tea"}};
    assert(groupAnagram.solution1(input1) == output1);

    // Test 2
    vector<string> input2 = {""};
    vector<vector<string>> output2 = {{""}};
    assert(groupAnagram.solution1(input2) == output2);

    // Test 3
    vector<string> input3 = {"a"};
    vector<vector<string>> output3 = {{"a"}};
    assert(groupAnagram.solution1(input3) == output3);

    // Test 4
    vector<string> input4 = {"a", "cat", "dog"};
    vector<vector<string>> output4 = {{"a"}, {"cat"}, {"dog"}};
    assert(groupAnagram.solution1(input4) == output4);


    return 0;
}





