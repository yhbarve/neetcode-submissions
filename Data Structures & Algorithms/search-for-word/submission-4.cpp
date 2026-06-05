class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string word, int i, int x, int y){
        if (board[x][y] != word[i]) return false;
        if (i == word.size() - 1) return true; // the last character has been matched, so we've found the word!

        // check the four neighbours
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto d : directions){
            int newX = x + d.first;
            int newY = y + d.second;
            if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size()){
                board[x][y] = '*';
                if (backtrack(board, word, i + 1, newX, newY)) return true;
                board[x][y] = word[i];
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        /*
            - We need to match letters as well as their position in the word.
            - If the current letter is not the one we're looking for, stop.
        */
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] == word[0]){
                    if (backtrack(board, word, 0, i, j)) return true;
                }
            }
        }
        return false;
    }
};
