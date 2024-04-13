
// Need to watch video plus  don;t understand the poitn of skipping
// the first character of duplicated.

vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> output;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            int k = i + 1;
            int j = nums.size() - 1;
            
            while (k < j) {
                
                int current_sum = nums[i] + nums[j] + nums[k];
                
                if (current_sum > 0) {
                    j--;
                }
                
                else if (current_sum < 0) {
                    k++;
                }
                
                else {
                    
                    output.push_back({nums[i], nums[j], nums[k]});
                    k++;
                    while (k < j && nums[k] == nums[k-1]) {
                        k++;
                    }
                    
                }
                
            }
            
        }
            
            
            return output;
            
            
        };