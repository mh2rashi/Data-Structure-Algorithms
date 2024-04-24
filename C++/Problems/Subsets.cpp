

// You build fomr the ground up, still need to do its Space and Time COmplexity

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> subsets = {{}};
        
        for (int num : nums) {
            
            int subset_size = subsets.size();
            
            for (int i = 0; i < subset_size; i++) {
                // Create and add a new subset
                vector<int> new_subset = subsets[i];
                new_subset.push_back(num);
                
                // Add to our 
                subsets.push_back(new_subset);  
            }
        }
        
        return subsets;
          
    }
};