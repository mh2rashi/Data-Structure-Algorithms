/*

4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints by Question:
- nums1.length == m
- nums2.length == n
- 0 <= m <= 1000
- 0 <= n <= 1000
- 1 <= m + n <= 2000
- -106 <= nums1[i], nums2[i] <= 106
 
*/

/*

Constraints

1. What is the min/max length of the array?
2. What is the min/max size of integers within the array?

Tets Cases
1. 

Ideas
1. Have an auxillary array to combine both values from each list, and then just
find the median. 
2. 


Complexity:
1. Time: O(m + n), Space: O(m + n).
2. Time: 


*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

class MedianOfTwoSortedArrays {
public:

    double solution1(vector<int>& nums1, vector<int>& nums2) {

        int totalSize = nums1.size() + nums2.size();

        if ( totalSize % 2 == 0) {


        }

        else {

            


        }
        
    
    
    }

};

int main() {

    return 0;
}