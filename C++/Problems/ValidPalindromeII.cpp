// It would be easier to send the entire string plus the indexes you want to check
// as opposed to substringing the string.

bool isPalindrome(const std::string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool validPalindrome(const std::string& s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            // Check if removing s[left] makes the substring s[left+1:right] a palindrome
            // OR removing s[right] makes the substring s[left:right-1] a palindrome
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
        left++;
        right--;
    }

    return true; // If we've checked all characters and found no mismatch
}