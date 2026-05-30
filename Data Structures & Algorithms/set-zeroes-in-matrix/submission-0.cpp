class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        set<int> rowsToMakeZero;
        set<int> colsToMakeZero;
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 0){
                    rowsToMakeZero.insert(i);
                    colsToMakeZero.insert(j);
                }
            }
        }

        for (auto r : rowsToMakeZero){
            for (int j = 0; j < n; j++){
                matrix[r][j] = 0;
            }
        }

        for (auto c : colsToMakeZero){
            for (int i = 0; i < m; i++){
                matrix[i][c] = 0;
            }
        }
    }
};
