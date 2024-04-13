// You could probably also just draw the different overlapping intervals


//   [  ]
// [        ]


// [  ]
 // [  ]

 //  [  ]
 // [  ]


// learn how to sort the intervals using a lambda function based on the 
// start of the itnerval.

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
    if (intervals.size() < 2) {
        return intervals;
    }
        
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> mergedIntervals;
        
    vector<int> currentInterval = intervals[0];
        
    for (int i = 1; i < intervals.size(); i++) {
        
        vector<int> nextInterval = intervals[i];
        
        // Non-overlapping;
        if (currentInterval[1] < nextInterval[0]) {
            
            mergedIntervals.push_back(currentInterval);
            currentInterval = nextInterval;
        }
        
        
        // Overlapping
        else {
            currentInterval[0] = min(currentInterval[0], nextInterval[0]);
            currentInterval[1] = max(currentInterval[1], nextInterval[1]);   
        }
        
    }
        
    mergedIntervals.push_back(currentInterval);
    return mergedIntervals;
        
    }
};