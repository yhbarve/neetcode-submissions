class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> sol;
        if (intervals.size() == 1) return intervals;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++){
            if (end < intervals[i][0]){
                sol.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            } else {
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }
        sol.push_back({start, end});
        return sol;
    }
};
