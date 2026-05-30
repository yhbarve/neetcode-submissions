class Solution {
public:
    int backtrack(int m, int n, int i, int j){
        if (i == m-1 && j == n-1) return 1;
        if (i == m || j == n) return 0;
        return backtrack(m, n, i, j+1) + backtrack(m, n, i+1, j);
    }

    int uniquePaths(int m, int n) {
        return backtrack(m, n, 0, 0);
    }
};
