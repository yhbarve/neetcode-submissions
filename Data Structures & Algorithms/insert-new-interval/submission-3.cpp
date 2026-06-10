class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // a, b, c, d, e
        // x
        // a.end > x.begin, c.begin < x.end
        // [a.start, c.end], d, e

        // stack<vector<int>> st;
        // st.push(newInterval);
        vector<vector<int>> st;
        int idx = 0;
        st.push_back(newInterval);
        idx++;
        for (auto i : intervals){
            if (i[1] < st[idx-1][0]){
                vector<int> temp = st[idx-1];
                st[idx-1] = i;
                st.push_back(temp);
                idx++;
            } else if (i[0] > st[idx-1][1]){
                st.push_back(i);
                idx++;
            } else {
                vector<int> temp = st[idx-1];
                st[idx-1] = {min(temp[0], i[0]), max(temp[1], i[1])};
            }
        }
        return st;
    }
};
