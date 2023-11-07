def merge(intervals):
    if len(intervals) <= 1:
        return intervals
    intervals.sort(key = lambda x : x[0])
    i = 0
    stop = len(intervals) - 1
    while i != stop:
        if intervals[i][1] >= intervals[i+1][0]:
            if intervals[i][1] >= intervals[i+1][1]:
                new_interval = intervals[i]
            else:
                new_interval = [intervals[i][0],intervals[i+1][1]]
            intervals[i] = new_interval
            intervals.pop(i+1)
            stop = len(intervals) - 1
        else:
            i += 1
    return intervals

print(merge([[1,4],[4,5]]))

