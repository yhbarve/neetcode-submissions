class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // a, b, c, d, e
        // x
        // a.end > x.begin, c.begin < x.end
        // [a.start, c.end], d, e

        stack<vector<int>> st;
        st.push(newInterval);

        for (auto i : intervals){
            if (i[1] < st.top()[0]){
                vector<int> temp = st.top();
                st.pop();
                st.push(i);
                st.push(temp);
            } else if (i[0] > st.top()[1]){
                st.push(i);
            } else {
                vector<int> temp = st.top();
                st.pop();
                st.push({min(temp[0], i[0]), max(temp[1], i[1])});
            }
        }

        vector<vector<int>> sol;
        while (!st.empty()){
            sol.push_back(st.top());
            st.pop();
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};
