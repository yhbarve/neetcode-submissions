class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int left = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;

        vector<int> sol;

        while (top <= bottom && left <= right){
            for (int i = left; i <= right; i++){
                sol.push_back(matrix[top][i]);
            }
            top++;
            if (top > bottom) return sol;
            for (int i = top; i <= bottom; i++){
                sol.push_back(matrix[i][right]);
            }
            right--;
            if (right < left) return sol;
            for (int i = right; i >= left; i--){
                sol.push_back(matrix[bottom][i]);
            }
            bottom--;
            if (bottom < top) return sol;
            for (int i = bottom; i >= top; i--){
                sol.push_back(matrix[i][left]);
            }
            left++;
            if (left > right) return sol;
        }

        return sol;
    }
};
