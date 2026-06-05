class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        /*
            c a t !
          c 3 2 1 0   
          r       0
          a       0
          b     1 0
          t     1 0
          ! 0 0 0 0  
        */

        vector<vector<int>> dp(text2.size()+1, vector<int>(text1.size()+1, 0));
        for (int i = text2.size() - 1; i >= 0; i--){
            for (int j = text1.size() - 1; j >= 0; j--){
                if (text1[j] == text2[i]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
