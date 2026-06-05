class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string word, int i, int x, int y, vector<vector<bool>> visited){
        cout << i << ", " << x << ", " << y << endl;
        if (i == word.size()) return true; // we found the word
        if (x < 0 || x == board.size()) return false;
        if (y < 0 || y == board[0].size()) return false;
        if (visited[x][y]) return false;
        visited[x][y] = true;
        if (board[x][y] != word[i]) return false;
        if (i == word.size() - 1) return true;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto d : directions){
            int newX = x + d.first;
            int newY = y + d.second;
            if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size() && !visited[newX][newY] && backtrack(board, word, i + 1, newX, newY, visited)){
                return true;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        /*
            - We need to match letters as well as their position in the word.
            - If the current letter is not the one we're looking for, stop.
        */
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] == word[0]){
                    if (backtrack(board, word, 0, i, j, visited)) return true;
                }
            }
        }
        return false;
    }
};
