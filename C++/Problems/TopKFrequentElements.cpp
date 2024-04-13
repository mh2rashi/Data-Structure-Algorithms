/*

347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Example 3:
Input: [1,2,3], k = 3
Output: [1,2,3]

Constraints by Question:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 
*/

/*

Constraints

1. What is the min/max length of the array? What is the min/max size of the integer within the array? What is the minimum size of k?
2. Do we need to return the elements within a specific order? Do we return the elements as a vector?
3. Does the array come sorted?


Tets Cases
1. Input: nums = [1,1,1,2,2,3], k = 2, Output: [1,2]
2. Input: nums = [1], k = 1, Output: [1]
3. Input: [1,2,3], k = 3, Output: [1,2,3]


Ideas
1. We sort the array, and then we loop through it until we find k distinct integers within our sorted array and each time we find a unique integer, we append it to our outputLst.
2. We loop through the array and use a hash map to store the frequencies for our integers. Then we create an array with pairs (frequency, value) and finally we traverse over the 
vector of pairs and extract the k most frequent elements and return this final list.
3. We loop through the array and have a vector<vector<int>> which adds integers based on frequency. This vector of vector will have atleast n (size of array) unique elements. We then
raverse it until we find k integers and append it to our array.

Complexity:
1.
2.
3.



*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

class TopKFrequentElements {
public:

    vector<string> solution1(vector<string>& strs) {
       
        vector<vector<string>> groupAnagramsLst = {};

        unordered_map<string, vector<string>> groupAnagramDict = {};

        for (auto phrase : strs) {

            string sorted_phrase = phrase;
            sort(sorted_phrase.begin(), sorted_phrase.end());

            if (groupAnagramDict.find(sorted_phrase) != groupAnagramDict.end()) {

                groupAnagramDict[sorted_phrase].push_back(phrase);
            }

            else {

                groupAnagramDict[sorted_phrase] = {phrase};
            }
        }

        for (const auto& pair: groupAnagramDict) {
            groupAnagramsLst.push_back(pair.second);
        }

        return groupAnagramsLst;
    
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
