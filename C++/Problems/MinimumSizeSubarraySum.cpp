int minSubArrayLen(int target, vector<int>& nums) {
        
        int output = INT_MAX;
        int currentSum = 0;
        
        int i = 0, j = 0;
        
        
        while (j < nums.size()) {
            
            currentSum += nums[j];
                
            while (currentSum >= target){

                output = min(output, j - i + 1);
                currentSum -= nums[i];
                i++;
            }
            
            j++;
              
        }

    return output == INT_MAX? 0 : output;
        
    }