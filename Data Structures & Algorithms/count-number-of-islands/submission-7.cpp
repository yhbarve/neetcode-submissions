class Solution {
public:
    void bfs(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited){
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0' || visited[x][y]){
            return;
        }

        visited[x][y] = true;

        bfs(grid, x+1, y, visited);
        bfs(grid, x-1, y, visited);
        bfs(grid, x, y+1, visited);
        bfs(grid, x, y-1, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        int sol = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1' && !visited[i][j]){
                    bfs(grid, i, j, visited);
                    sol++;
                }
            }
        }
        return sol;
    }
};
