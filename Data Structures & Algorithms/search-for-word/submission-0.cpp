class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string word, int i, int j, vector<pair<int, int>> idx){
        if (i < 0 || i >= board.size()) return false;
        if (j < 0 || j >= board[0].size()) return false;
        if (board[i][j] != word[idx.size()]) return false;
        if (board[i][j] == word[idx.size()] && std::find(idx.begin(), idx.end(), std::make_pair(i, j)) == idx.end()){
            idx.push_back({i, j});
            if (idx.size() == word.size()) return true;
            return backtrack(board, word, i+1, j, idx) ||
            backtrack(board, word, i-1, j, idx) ||
            backtrack(board, word, i, j+1, idx) ||
            backtrack(board, word, i, j-1, idx);
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (backtrack(board, word, i, j, {})) return true;
            }
        }
        return false;
    }
};
