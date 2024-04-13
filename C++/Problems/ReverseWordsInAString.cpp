//Need to learn how ot do this with O(1) space


class Solution {
public:
    std::string reverseWords(std::string s) {
        std::vector<std::string> strings;
        int right = 0;
        int n = s.size();

        // Extract words from the input string
        while (right < n) {
            // Skip leading spaces
            while (right < n && s[right] == ' ') {
                right++;
            }

            int left = right;

            // Find end of current word
            while (right < n && s[right] != ' ') {
                right++;
            }

            // Extract the current word and push it to the vector
            if (right > left) {
                strings.push_back(s.substr(left, right - left));
            }
        }

        // Reverse the order of words in the vector
        std::reverse(strings.begin(), strings.end());

        // Concatenate reversed words into a single string with spaces
        return std::accumulate(strings.begin(), strings.end(), std::string(),
                               [](const std::string& a, const std::string& b) {
                                   return a.empty() ? b : a + " " + b;
                               });
    }
};