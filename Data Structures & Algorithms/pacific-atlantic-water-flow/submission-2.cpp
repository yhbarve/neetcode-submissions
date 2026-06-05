class Solution {
public:
    void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<int>>& visited, int target){
        if (x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size() || heights[x][y] < target || visited[x][y]){
            return;
        }

        visited[x][y] = true;

        dfs(heights, x+1, y, visited, heights[x][y]);
        dfs(heights, x-1, y, visited, heights[x][y]);
        dfs(heights, x, y+1, visited, heights[x][y]);
        dfs(heights, x, y-1, visited, heights[x][y]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> visitedAtlantic(heights.size(), vector<int>(heights[0].size(), 0));
        vector<vector<int>> visitedPacific(heights.size(), vector<int>(heights[0].size(), 0));

        for (int i = 0; i < heights.size(); i++){
            dfs(heights, i, 0, visitedPacific, 0);
            dfs(heights, i, heights[0].size() - 1, visitedAtlantic, 0);
        }

        for (int j = 0; j < heights[0].size(); j++){
            dfs(heights, 0, j, visitedPacific, 0);
            dfs(heights, heights.size() - 1, j, visitedAtlantic, 0);
        }

        vector<vector<int>> sol;
        for (int i = 0; i < heights.size(); i++){
            for (int j = 0; j < heights[0].size(); j++){
                if (visitedAtlantic[i][j] && visitedPacific[i][j]) sol.push_back({i, j});
            }
        }
        return sol;
    }
};
