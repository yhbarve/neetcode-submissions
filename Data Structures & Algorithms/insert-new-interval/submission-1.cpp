class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> sol;
        for (int i = 0; i < intervals.size(); i++){
            //  new interval is before the current interval
            if (newInterval[1] < intervals[i][0]){
                // cout << "XX" << endl;
                sol.push_back(newInterval);
                for (int j = i; j < intervals.size(); j++){
                    // cout << "X" << endl;
                    sol.push_back(intervals[j]);
                }
                return sol;
            }
            // new interval is after the current interval
            else if (newInterval[0] > intervals[i][1]){
                // cout << "Y" << endl;
                sol.push_back(intervals[i]);
            } else {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }
        sol.push_back(newInterval);
        return sol;
    }
};
