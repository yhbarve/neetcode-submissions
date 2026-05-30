class Solution {
public:
    void helper(vector<vector<int>>& heights, int i, int j, vector<vector<vector<bool>>>& visited, int ocean){
        cout << i << ", " << j << " -> " << heights[i][j] << endl;
        if (visited[i][j][ocean]) return;
        visited[i][j][ocean] = true;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto [x, y] : directions){
            cout << "Trying " << i+x << ", " << j+y << endl;
            if (i+x < 0 || i+x >= heights.size()) continue;
            if (j+y < 0 || j+y >= heights[0].size()) continue;
            if (heights[i+x][j+y] >= heights[i][j]) helper(heights, i+x, j+y, visited, ocean);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<vector<bool>>> visited(
            m,
            vector<vector<bool>>(n, vector<bool>(2, false))
        );
        for (int j = 0; j < n; j++){
            cout << "running" << endl;
            helper(heights, 0, j, visited, 0);
            cout << "haha" << endl;
            helper(heights, m-1, j, visited, 1);
        }
        for (int i = 0; i < m; i++){
            cout << "running" << endl;
            helper(heights, i, 0, visited, 0);
            cout << "haha" << endl;
            helper(heights, i, n-1, visited, 1);
        }

        vector<vector<int>> sol;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (visited[i][j][0] && visited[i][j][1]) sol.push_back({i, j});
            }
        }

        return sol;
    }
};
