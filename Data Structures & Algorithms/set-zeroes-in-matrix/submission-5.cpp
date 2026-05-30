class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
            [1, 0, 3, 1]
            [4, 0, 6, 0]
            [7, 8, 9, 3]
            [1, 2, 3, 4]
            [0, 2, 4, 1]

            [0, 1]
            [1, 1]
        */
        int m = matrix.size();
        int n = matrix[0].size();

        int topRow = 1;
        int topCol = 1;

        for (int j = 0; j < n; j++){
            if (matrix[0][j] == 0){
                topRow = 0;
                break;
            }
        }

        for (int i = 0; i < m; i++){
            if (matrix[i][0] == 0){
                topCol = 0;
                break;
            }
        }
        
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                if (matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // for (auto i : matrix){
        //     for (auto j : i){
        //         cout << j << ' ';
        //     }
        //     cout << endl;
        // }

        // cout << endl;

        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }

        // for (auto i : matrix){
        //     for (auto j : i){
        //         cout << j << ' ';
        //     }
        //     cout << endl;
        // }

        if (!topRow){
            for (int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }

        if (!topCol){
            for (int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }

    }
};
