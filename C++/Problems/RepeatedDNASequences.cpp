/*


the substring function in 

187. Repeated DNA Sequences

The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.
Given a string s that represents a DNA sequence, return all the 10-letter-long sequences
(substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

Constraints by Question:
1 <= s.length <= 105
s[i] is either 'A', 'C', 'G', or 'T'.

*/

/*

Constraints
1. Does the string only contain letters A, C, G, and T?
2. What is the min/max length of the string?
3. 



Tets Cases
1. "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT" -> ["AAAAACCCCC","CCCCCAAAAA"]
2. "AAAAAAAAAAAAA" -> ["AAAAAAAAAA"]
3. "AAA" -> []
4. "AAACCCGGTT" -> ["AAACCCGGTT"]



Ideas
1. Have a window of 10 charaters and iterate through the string, also populate a
dictionary with the frequency of each DNA sequence. Return the sequences that have
more than 1 frequency.


Complexity:
1. Time: O(N), Space: O(N); where N is the number of itnegers within the array.
Time could've havve been 


Time Complexity:

The substr function in C++ typically has a time complexity of O(m), where m is the length of the substring being extracted.
If you are searching for subsequences of length m at various positions in the string, the time complexity will depend on the number of times you invoke substr and the length of each substring.
If you are searching for subsequences of length m across the entire string, and assuming the length of the original string is n, you may invoke substr up to (n - m + 1) times (to cover all possible starting positions for a substring of length m). Therefore, the overall time complexity could be O((n - m + 1) * m), which simplifies to O(n * m) in the worst case scenario.

Space Complexity:

The space complexity of the substr function itself is O(m), where m is the length of the substring being extracted.
In addition to the space used by substr, you may also need additional space to store the subsequences or results. If you are storing all found subsequences, the space complexity could be O((n - m + 1) * m), where n is the length of the original string.

*/



#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

// Wrong approach
vector<string> findRepeatedDnaSequences1(string s) {
        
    vector<string> output = {};
    unordered_map<string,int> sequences;

    if (s.size() < 10) {
        return output;
    }
    // I needed to have the following i <= s.size() - 10
    for (int i = 0; i < s.size() - 9; i++) {

        string currentString = s.substr(0 + i, 9 + i);

        sequences[currentString]++;
    }

    for (const auto& pair : sequences) {
        if (pair.second > 1) {
            output.push_back(pair.first);
        }
    }

    return output;

}

// Correct approach
vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> output = {};
        unordered_map<string,int> sequences;

        if (s.size() < 10) {
            return output;
        }

        for (int i = 0; i <= s.size() - 10; i++) {

            string currentString = s.substr(0 + i, 10);

            sequences[currentString]++;
        }

        for (const auto& pair : sequences) {
            if (pair.second > 1) {
                output.push_back(pair.first);
            }
        }

        return output;

        }

int main() {

    string test1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    findRepeatedDnaSequences(test1);

    return 0;
};

