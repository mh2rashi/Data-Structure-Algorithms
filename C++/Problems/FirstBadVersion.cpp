/// Use long long for an extremely large integer


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int long long start = 0;
        int long long end = n;
        
        int long long bad_index = n;
        
        
        while (start <= end) {
            
            int long long mid = (start + end)/2;
            
            if (!isBadVersion(mid)) {
                
                start = mid + 1;
            }
            
            else {
                
                bad_index = mid;
                end = mid - 1;
            }
         
        }
        
    return bad_index;
        
    }
};


