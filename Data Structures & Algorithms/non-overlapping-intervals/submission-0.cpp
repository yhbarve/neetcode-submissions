class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return 0;
        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1];
        int ct = 0;
        for (int i = 1; i < intervals.size(); i++){
            if (prevEnd <= intervals[i][0]) prevEnd = intervals[i][1];
            else{
                ct++;
                prevEnd = min(intervals[i][1], prevEnd);
            }
        }
        return ct;
    }
};
