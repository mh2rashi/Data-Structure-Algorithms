// Could honestly clean up my solution, especially inserting the remianing list after w've inserted
// the newInterval


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        if (intervals.size() == 0) {
            return {newInterval};
        }
        
        bool inserted = false;
        
        vector<vector<int>> output;
        
        for (int i = 0; i < intervals.size(); i++) {
            
            vector<int> currentInterval = intervals[i];
            
            if (inserted) {
                
                output.push_back(currentInterval);
                
            }

            else if (newInterval[1] < currentInterval[0]) {
                
                inserted = true;
                
                output.push_back(newInterval);
                output.push_back(currentInterval);
                
                
            }
            
            else if (currentInterval[1] < newInterval[0]) {
                output.push_back(currentInterval);
            }
            
            else {
                
                newInterval[0] = min(currentInterval[0], newInterval[0]);
                newInterval[1] = max(currentInterval[1], newInterval[1]);   
                
            }
        
        }
        
        if (!inserted) {
            
            output.push_back(newInterval);
            
        }
        
        return output;
        
        
    }