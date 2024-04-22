/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int max_rooms = 0;

        for (Interval& interval : intervals) {

            if (minHeap.empty()) {
                minHeap.push(interval.end);
            }
            
            else if (minHeap.top() > interval.start) {
                minHeap.push(interval.end);
            }
            
            // This not empty condition is important
            else {
                while (!minHeap.empty() && minHeap.top() <= interval.start) {
                    minHeap.pop();
                }

                minHeap.push(interval.end);
            }

            max_rooms = max(static_cast<int>(minHeap.size()), max_rooms);
        }

        return max_rooms;
    }
};
