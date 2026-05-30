class Solution {
public:
    void process(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited){
        // cout << "i = " << i << ", j = " << j << endl;
        if (i < 0 || i >= grid.size()) return;
        if (j < 0 || j >= grid[0].size()) return;
        if (visited[i][j] == true) return;
        visited[i][j] = true;
        if (grid[i][j] == '1'){
            process(grid, i+1, j, visited);
            process(grid, i-1, j, visited);
            process(grid, i, j+1, visited);
            process(grid, i, j-1, visited);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int islands = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1' && visited[i][j] == false){
                    // cout << endl;
                    // cout << "I = " << i << ", J = " << j << endl;
                    // cout << endl;
                    islands += 1;
                    process(grid, i, j, visited);
                }
            }
        }
        return islands;
    }
};
