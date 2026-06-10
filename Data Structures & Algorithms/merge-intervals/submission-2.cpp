class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> sol;
        sol.push_back(intervals[0]);

        for (auto i : intervals){
            if (i[1] < sol.back()[0]){
                vector<int> temp = sol.back();
                sol[sol.size() - 1] = i;
                sol.push_back(temp);
            } else if (i[0] > sol.back()[1]){
                sol.push_back(i);
            } else {
                vector<int> temp = sol.back();
                sol[sol.size() - 1] = {min(temp[0], i[0]), max(temp[1], i[1])};
            }
        }
        return sol;
    }
};
