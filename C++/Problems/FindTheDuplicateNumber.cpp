// Solution
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++) {
            
            int num_index = abs(nums[i]) - 1;
            
            if (nums[num_index] < 0) {
                return abs(nums[i]);
            }
            
            else {
                nums[num_index] *= -1;
            }
        }
        
        return -1;
    };
};