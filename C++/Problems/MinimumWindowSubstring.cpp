


// This is the optimized using Time: O(m + n)
// Space: O(s + t)
string minWindow(string s, string t) {
        // count of char in t
        unordered_map<char, int> mTap;
        for (const auto& character : t) {
            mTap[character]++;
        }
        
        int i = 0;
        int j = 0;
        
        // # of chars in t that must be in s
        int counter = t.size();
        
        int minStart = 0;
        int minLength = INT_MAX;
        
        while (j < s.size()) {
            // if char in s exists in t, decrease
            if (mTap[s[j]] > 0) {
                counter--;
            }
            
            // if char doesn't exist in t, will be -'ve
            mTap[s[j]]--;
            // move j to find valid window
            j++;
            
            // when window found, move i to find smaller
            while (counter == 0) {
                if (j - i < minLength) {
                    minStart = i;
                    minLength = j - i;
                }
                
                mTap[s[i]]++;
                // when char exists in t, increase
                if (mTap[s[i]] > 0) {
                    counter++;
                }
                i++;
            }
        }
        
        if (minLength != INT_MAX) {
            return s.substr(minStart, minLength);
        }
        return "";
    }


/*
When encountering a character s[j] that exists in tMap,
you should decrement its count in tMap. If the count becomes zero or negative,
it means this character is no longer needed in the window, so you decrement counter.
When shrinking the window by moving i to the right (i++), you should restore
the counts of characters in tMap. If a character's count in tMap becomes positive again (indicating it's needed to form a valid window), you increment counter.

Characters that were never found in our iniitial loop for populating tMap will
always be 0 or negative becasue once we find them in our j pointer we will
decrement the counter (beocming negative) but once we find them in our i pointer
we will increment leading to them being resotred to 0.

THe characters that are in t will always have a coutn > 0 to begin with.

*/