class Solution {
public:
    void bfs(vector<vector<char>>& grid, int x, int y, int m, int n, vector<vector<bool>>& visited){
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            // cout << "NOW PROCESSING: " << x << ", " << y << endl;
            q.pop();
            // cout << "Reached " << x << ", " << y << endl;
            visited[x][y] = true;
            // cout << "Marked " << x << ", " << y << " = visited" << endl;
            // if (visited[x][y]) cout << "visited for " << x << ", " << y << " is marked true" << endl;

            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (auto d : directions){
                int newX = x + d.first;
                int newY = y + d.second;
                // cout << "Trying " << newX << ", " << newY << endl;
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY] && grid[newX][newY] == '1'){
                    // cout << "Pushing " << newX << ", " << newY << endl;
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int numIslands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                // if (visited[i][j]) cout << "visited for " << i << ", " << j << " is true" << endl;
                // else cout << "visited for " << i << ", " << j << " is false" << endl;
                if (visited[i][j] == false && grid[i][j] == '1'){
                    numIslands++;
                    cout << endl;
                    // cout << "Attempting " << i << ", " << j << endl;
                    bfs(grid, i, j, m, n, visited);
                }
            }
        }
        return numIslands;
    }

    /*
        1, 1, 1, 1, 0
        1, 1, 0, 1, 0
        1, 1, 0, 0, 0
        0, 0, 0, 0
    */
};
