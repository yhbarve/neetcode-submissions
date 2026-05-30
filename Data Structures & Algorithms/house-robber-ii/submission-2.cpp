class Solution {
public:
    int helper(vector<int>& nums, int i, int j){
        int n = j - i + 1;
        vector<int> sol(n, 0);
        sol[0] = nums[i+0];
        sol[1] = max(sol[0], nums[i+1]);
        for (int x = 2; x <= n; x++){
            sol[x] = max(sol[x-1], sol[x-2]+nums[x+i]);
        }
        return sol.back();
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        return max(helper(nums, 0, nums.size() - 2), helper(nums, 1, nums.size() - 1));
    }
};
