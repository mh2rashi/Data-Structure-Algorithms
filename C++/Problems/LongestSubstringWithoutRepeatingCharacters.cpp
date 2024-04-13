int lengthOfLongestSubstring(string s) {
        
    int i = 0, j = 0;
    int maxLength = 0;
    unordered_map<char, int> frequency;
    int s_size = s.size();
    
    while (j < s_size) {
        // Increment frequency of s[j]
        frequency[s[j]]++;
        
        // Check if s[j] is repeated
        if (frequency[s[j]] > 1) {
            // Increment counter if s[j] is repeated
            // Note: we need to move i to remove the repetition
            while (frequency[s[j]] > 1) {
                frequency[s[i]]--; // Decrement frequency of s[i]
                i++; // Move i to the right to remove repeated characters
            }
        }
        
        // Update maxLength if currentLength is greater
        maxLength = max(maxLength, j - i + 1);
        
        // Move j to the right to expand the window
        j++;
    }
    
    return maxLength;}
};