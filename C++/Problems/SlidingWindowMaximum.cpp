/*


239. Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from
the very left of the array to the very right. You can only see the k numbers in the window.
Each time the sliding window moves right by one position.

Return the max sliding window.

Constraints by Question:
- 1 <= nums.length <= 105
- -104 <= nums[i] <= 104
- 1 <= k <= nums.length

*/

/*

Constraints
1. What is the min/max value of integers within the array?
2. What is the min/max size of the array? k <= n?
3. Can you have repeating integers?


Tets Cases
1. [1,3,-1,-3,5,3,6,7], k = 3 => [3,3,5,5,6,7]
2. [1], k = 1 -> 1;



Ideas
1. Use the deque data structure to come up with a monotonically decreasing que. We add elements
to the back of the queue if they are less than the end element. We also add element
to the front of the queue if they are greater than the front. At any time we can only have
at most k elements within the que.


*/



#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

// This solution was good but it didn't pass the followign case 
// [1,3,1,2,0,5], k = 3
// output -> [3,2,3,5]
// expected -> [3,3,2,5]


// This approach was wrong.
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
   vector<int> output = {};
    deque<int> dq;

    int right = 0;

    while (right < k) {

        if (dq.empty()) {
            dq.push_front(nums[right]);
            right++;
        }

        else if (nums[right] <= dq.back()) {
            dq.push_back(nums[right]);
            right++;
        }

        else {

            while (!dq.empty() && nums[right] > dq.front()) {
                dq.pop_front();
            }

            dq.push_front(nums[right]);
            right++;

        }
    }

    output.push_back(dq.front());

    while (right < nums.size()) {

        if (dq.size() == k) {
            dq.pop_front();
        }

        if (dq.empty()) {
            dq.push_front(nums[right]);
            right++;
        }

        else if (nums[right] <= dq.back()) {
            dq.push_back(nums[right]);
            right++;
        }

        else {

            while (!dq.empty() && nums[right] > dq.front()) {
                dq.pop_front();
            }

            dq.push_front(nums[right]);
            right++;

        }

        output.push_back(dq.front());


    }

     return output;
        
}

// Second attempt still wrong
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
    vector<int> output = {};
    deque<int> dq;

    for (int i = 0; i < nums.size(); i++) {

        if (dq.size() == k) {
            dq.pop_front();
        }

        if (dq.empty()) {
            dq.push_front(nums[i]);
        }

        else if (nums[i] <= dq.back()) {
            dq.push_back(nums[i]);
        }

        else {

            while (!dq.empty() && nums[i] > dq.front()) {
                dq.pop_front();
            }

            dq.push_front(nums[i]);

        }

        if (i >= k - 1) {
            output.push_back(dq.front());

        }
    }

     return output;
    
}


// correct approach

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
    vector<int> output;
    deque<int> dq;

    int n = nums.size();

    for (int right = 0; right < n; right++) {
        // Remove elements from the front of deque if they are out of the current window range
        if (!dq.empty() && dq.front() < right - k + 1) {
            dq.pop_front();
        }

        // Remove elements from the back of deque if they are less than or equal to the current number
        while (!dq.empty() && nums[dq.back()] <= nums[right]) {
            dq.pop_back();
        }

        // Add current number's index to the back of deque
        dq.push_back(right);

        // Once we have a full window of size k, add the maximum element to the output
        if (right >= k - 1) {
            output.push_back(nums[dq.front()]);
        }
    }

    return output;}

int main() {

    string test1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    findRepeatedDnaSequences(test1);

    return 0;
};