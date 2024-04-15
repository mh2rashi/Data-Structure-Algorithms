class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector<vector<int>> output;
        int i = 0;
        int j = 0;
        
        // Whatever interval you over cross
        while (i < firstList.size() && j < secondList.size()) {
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];
            
            // This is the overlapping condition
            if (end1 >= start2 && end2 >= start1) {
                vector<int> mergedInterval;
                
                // For overlapping you will take the max start and the min ending
                mergedInterval.push_back(max(start1, start2));
                mergedInterval.push_back(min(end1, end2));
                output.push_back(mergedInterval);
            }
            
            // Move to the next interval with the smaller end time, you want to keep the smaller end time.
            if (end1 < end2) {
                i++;
            } else {
                j++;
            }
        }
        
        return output;
    }
};



/*Question 1: So for your next else condition within the while loop you will increment i if end1 < end2 because you know that any merging for that interval is laready taken care of?


Yes, you are correct in your understanding. Let's clarify the purpose of the logic within the while loop, especially the handling of the else condition where i or j is incremented based on the comparison of end times (end1 and end2).

The purpose of incrementing i or j based on the comparison of end times (end1 and end2) is to efficiently move to the next interval comparison in firstList (i) or secondList (j). Here's the breakdown:

Comparison of End Times:

end1 is the end time of the current interval from firstList.
end2 is the end time of the current interval from secondList.
Incrementing Indices:

If end1 < end2: This means that the current interval from firstList ends before the current interval from secondList. Since we are processing intervals in a sorted manner based on their end times, we can safely move to the next interval in firstList (i++), knowing that any potential overlap involving the current interval from firstList has been considered.

If end1 >= end2: This means that the current interval from secondList ends before or at the same time as the current interval from firstList. In this case, we move to the next interval in secondList (j++), as the current interval from secondList has either been merged with or does not overlap with any subsequent interval from firstList.

Efficient Iteration:

By incrementing i or j based on the end time comparison, we ensure that we efficiently move through the lists and process intervals in a sorted manner based on their end times. This approach helps avoid unnecessary comparisons and ensures that we handle each interval appropriately in relation to the intervals from the other list.

*/