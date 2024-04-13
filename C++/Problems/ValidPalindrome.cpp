// Solution 1
class Solution {
public:
 bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while (i < j) {
            while (!isalnum(s[i]) && i < j) {
                i++;
            }
            while (!isalnum(s[j]) && i < j) {
                j--;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
};


// Solution 2
    bool isPalindrome(string s) {
        
        string mod_s = "";
        
        for (const auto& character : s) {
            if (isalnum(character)) {
                mod_s += tolower(character);
            }
        }
        
        int i = 0, j = mod_s.size() - 1;
        
        while (i <= j) {
            
            if (mod_s[i] != mod_s[j]) {
                return false;
            }
            
            i++;
            j--;
            
        }
        
        return true;
        
    }