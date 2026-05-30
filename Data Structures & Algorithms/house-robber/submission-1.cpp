class Solution {
public:
    int backtrack(vector<int>& nums, int i, vector<int>& dp){
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];
        return dp[i] = max(nums[i] + backtrack(nums, i+2, dp), backtrack(nums, i+1, dp));
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return backtrack(nums, 0, dp);
    }
};
