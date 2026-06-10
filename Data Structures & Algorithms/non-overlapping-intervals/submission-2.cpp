class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];
        int toDelete = 0;
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][1] <= start) continue;
            if (intervals[i][0] >= end){
                start = intervals[i][0];
                end = intervals[i][1];
                continue;
            }
            toDelete++;
            cout << "interval = " << intervals[i][0] << ", " << intervals[i][1];
            cout << " & curr = " << start << ", " << end << endl;
            start = min(intervals[i][0], start);
            end = min(intervals[i][1], end);
            cout << "update -> " << start << ", " << end << endl;
        }
        return toDelete;
    }

    /*
        [0,  2]
          [1,  3]
            [2,  4]
              [3,  5]
                [4,  6]
    */
};
