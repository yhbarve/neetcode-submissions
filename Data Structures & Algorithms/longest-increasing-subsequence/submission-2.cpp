class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int maxLIS = 0;
        for (int i = 0; i < nums.size(); i++){
            int sol = 1;
            for (int j = i - 1; j >= 0; j--){
                // cout << nums[i] << " vs " << nums[j] << endl;
                if (nums[j] < nums[i]){
                    // cout << "sol prev = " << sol << endl;
                    sol = max(sol, 1 + dp[j]);
                    // cout << "dp[j] = " << dp[j] << ", sol after = " << sol << endl;
                    // cout << endl;
                }
            }
            dp[i] = sol;
            maxLIS = max(maxLIS, dp[i]);
        }
        
        return maxLIS;
    }
};
