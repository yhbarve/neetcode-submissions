class Solution {
public:
    int backtrack(int m, int n, int x, int y, vector<vector<int>>& mp){
        if (x == m || y == n) return 0;
        if (x == m - 1 && y == n - 1) return 1;
        if (mp[x][y] != -1) return mp[x][y];
        return mp[x][y] = backtrack(m, n, x+1, y, mp) + backtrack(m, n, x, y+1, mp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> mp(m, vector<int>(n, -1));
        return backtrack(m, n, 0, 0, mp);
    }
};
