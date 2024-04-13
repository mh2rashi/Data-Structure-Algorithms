/*

Do we use "" or '' for string.

you can;t do: string x = sort(y.begin(), y.end());
you need to do string x = y;
sort(y.begin(), y.end());

49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

Constraints by Question:
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
 
*/

/*

Constraints

1. What is the max/min length of the array and the max lenght of a string within the array?
2. Does the array come sorted in any way?
3. For a word to be an anagram, does it have to match the exactly words once?
4. What do the string characters consist of?


Tets Cases
1. ['eat','seat','tea'] -> [['eat','tea'],['seat']]
2. [""] -> [[""]]
3. ["a"] -> [["a"]]


Ideas
1. Double for loop, the first loop will be on a specific string, and the inner for loop will check if the current string is an anagram of the string of the outer loop. if so, then we 
will add the current list -> Problem with this solution is that if we iterate over a string that has already been added, than that would be a problem.
2. Create a dictionary (string, vector<string>). Loop over the list, if the string (sorted) exists within the dicitonary, the append it to the list, otherwise, create the key and append the string to the list.
3. Using the hint that the list only contains lowercase alphabets. If two strings are anagrams, then
their frequency of characters is the same.


Complexity:
1. Time O(N^2 * k log k), Space O(N). where N is the number of strings and k is the 
length of the longest string. -> problem solution
2. Time O(N * k log k), Space O(N). where N is the number of strings and k is the 
length of the longest string.


*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

class GroupAnagram {
public:

    vector<vector<string>> solution1(vector<string>& strs) {
       
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
