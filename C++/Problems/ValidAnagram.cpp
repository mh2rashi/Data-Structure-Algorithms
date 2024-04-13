/*

242. Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false

*/

/*

Constraints

1. What is the maximum length for each of the strings? Can the string t have more characters than string s?
2. If s is empty and then t has a number of digits, is t still an anagram of s?
3. It says to use the letters exactly, so no excess letters left?
4. only lowercase english letters for both.
5. I'm assuming characters can be repeated?
6. Can the string contain unicode characters?

Tets Cases

1. s = "car", t = "rac" -> true
2. s = "rat", t = "car" -> false
3. s = "anagram", t = "nagaram" -> true
4. s = "carr", t="rrrax" -> true
5. s="er", t="" -> false.

Ideas

1. Loop through s and count the characters in it and put them into a dictionary. Then loop through t and update the dictionary
if a character is found (aka subtract it). Then check if the dictionaries' values are all zero. If not return false.
2. Another apprach could be to sort both of them and check if they equal each other.

Complexity:
1. O(s) space and O(2s + t) time. Where s is the lenhght of the s string and t is the lenght of the t string.
2. O(slogs) + O(tlog)

*/

#include <cassert>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class ValidAnagram {

    public:

     bool solution1(string s, string t) {

        if (s.size() != t.size()){
            return false;
        };

        // Each individual character is a char
        unordered_map<char, int> s_characters;

        for (char character : s) {
            s_characters[character]++;
        }

        for (char character : t) {
            if (s_characters.find(character) !=  s_characters.end()) {
                s_characters[character]--;
            }
        }

        for (const auto& pair : s_characters) {
            if (pair.second > 0) {
                return false;
            }
        }

        return true;

    }

    bool solution2(string s, string t) {

        if (s.size() != t.size()){
            return false;
        };

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;

    }

    

};

int main() {

    ValidAnagram validAnagram;

    // Test 1
    string s1 = "car", t1 = "rac";
    assert(validAnagram.solution1(s1,t1) == true);
    assert(validAnagram.solution2(s1, t1) == true);

    // Test 2
    string s2 = "rat", t2 = "car";
    assert(validAnagram.solution1(s2, t2) == false);
    assert(validAnagram.solution2(s2, t2) == false);

    // Test 3
    string s3 = "anagram", t3 = "nagaram";
    assert(validAnagram.solution1(s3, t3) == true);
    assert(validAnagram.solution2(s3, t3) == true);

    // Test 4
    string s4 = "carr", t4 ="rrrax";
    assert(validAnagram.solution1(s4, t4) == false);
    assert(validAnagram.solution2(s4, t4) == false);

    // Test 5
    string s5 ="er", t5 =" ";
    assert(validAnagram.solution1(s5, t5) == false);
    assert(validAnagram.solution2(s5, t5) == false);

    return 0;
};
